#include "Game.hpp"
#include <iostream>
#include "include/json.hpp"
#include "include/stb_image_write.h"

using json = nlohmann::json;
Game::Game()
{
	InitGame();
}


void Game::Draw()
{
	for (auto& sofa : m_sofas)
	{
		sofa.Draw();
	}

	for (auto& hostess : m_hostesses)
	{
		hostess.Draw();
	}
}

void Game::Update()
{
	for (auto& sofa : m_sofas)
	{
		sofa.Update();
	}

	HandleInputs();
	displayHostessesFaces();

}

void Game::HandleInputs()
{
	handlePlacingHostess();

	handleSelectingHostesses();
}

void Game::placeHostess(Hostess& hostess, Sofa& sofa)
{
	hostess.m_position = sofa.m_position;
	hostess.m_position.y -= 50;
	sofa.m_isBeingUsed = true;
	hostess.m_isBeingUsed = true;
	hostess.m_isCurrentlySelected = false;
	sofa.m_currentHostess = &hostess;
}

void Game::InitGame()
{
	std::cout << "GAME STARTED!\n";
	m_sofas = CreateSofas();
	std::cout << m_sofas.size();
	//CreateHostesses();
	initHostesses();
}

std::vector<Sofa> Game::CreateSofas()
{
	int offsetX = 400;
	int offsetY = 150;
	std::vector<Sofa> sofas;
	for (int row = 0; row < 2; ++row)
	{
		for (int column = 0; column < 2; ++column)
		{
			float x = offsetX + column * 350;
			float y = offsetY + row * 360;
			sofas.push_back(Sofa({ x, y }));
		}
	}
	return sofas;
}

void Game::displayHostessesFaces()
{
	int count = 1;
	for (auto& hostess : m_hostesses)
	{
		if (hostess.m_isBeingUsed == false)
		{
			hostess.m_faceImagePosition = { 100.0f, float(count * 100) };
			hostess.m_faceImageRectangle = hostess.getRect();
			DrawTexture(hostess.m_faceImage, 100, count * 100, WHITE);
			if (hostess.m_isCurrentlySelected == true)
			{
				DrawRectangleLines(100, count * 100, hostess.m_faceImage.width, hostess.m_faceImage.height, GREEN);
			}
			else
			{
				DrawRectangleLines(100, count * 100, hostess.m_faceImage.width, hostess.m_faceImage.height, WHITE);
			}
		}

		count++;
	}
}

void Game::handleSelectingHostesses()
{
	for (auto& hostess : m_hostesses)
	{
		if (!hostess.m_isBeingUsed)
		{
			Vector2 mousePosition = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePosition, hostess.m_faceImageRectangle))
			{
				unselectAllHostesses();
				hostess.m_isCurrentlySelected = !hostess.m_isCurrentlySelected;
				std::cout << hostess.name << " is currently " << (hostess.m_isCurrentlySelected ? "" : "NOT ") << "selected\n";
			}
				

		}
	}
}

void Game::initHostesses()
{
	m_hostesses[0].m_image = LoadTexture("resources/Images/fullBodyGirls/Angelica.png");
	m_hostesses[0].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Angelica-Head.png");
	m_hostesses[0].stats = { 100,10,10,10,10 };
	m_hostesses[0].traits = { 10,10,10,10 };
	m_hostesses[0].name = "Angel";

	m_hostesses[1].m_image = LoadTexture("resources/Images/fullBodyGirls/Clara.png");
	m_hostesses[1].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Clara-Head.png");
	m_hostesses[1].stats = { 100,10,10,10,10 };
	m_hostesses[1].traits = { 10,10,10,10 };
	m_hostesses[1].name = "Clara";
}

bool Game::isAHostessCurrentlySelected()
{
	for (auto& hostess : m_hostesses)
	{
		if (hostess.m_isCurrentlySelected == true)
			return true;
	}

	return false;
}

void Game::handlePlacingHostess()
{
	// Make ID system for the sofas, that way it will return the correct sofa
	for (int i = 0; i < m_sofas.size(); i++)
	{
		for (int j = 0; j < 2; j++) // 2 is the number of hostesses. will change later so not a magic number
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (CheckCollisionPointRec(GetMousePosition(), m_sofas[i].m_area))
				{
					std::cout << "Sofa number " << i << " has been pressed\n";
					if (!m_sofas[i].m_isBeingUsed && m_hostesses[j].m_isCurrentlySelected && m_hostesses[j].m_isBeingUsed == false)
					{
						std::cout << m_hostesses[j].name << " is sitting on sofa number " << i << std::endl;
						placeHostess(m_hostesses[j], m_sofas[i]);
					}
					else if (m_sofas[i].m_isBeingUsed && m_sofas[i].m_currentHostess == &m_hostesses[j])
					{
						m_sofas[i].m_isBeingUsed = false;
						m_hostesses[j].m_isBeingUsed = false;
						m_sofas[i].m_currentHostess = nullptr;
						std::cout << m_hostesses[j].name << " has been taken off sofa number " << i << std::endl;
					}
				}
			}
		}
	}
}

void Game::unselectAllHostesses()
{
	for (auto& hostess : m_hostesses)
	{
		hostess.m_isCurrentlySelected = false;
	}
}


