#include "Game.hpp"
#include <iostream>
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
}

void Game::Update()
{
	for (auto& sofa : m_sofas)
	{
		sofa.Update();
	}
}

void Game::HandleInputs()
{
	//Something
}

void Game::placeHostess(Hostess& hostess, Sofa& sofa)
{
	//DrawTexture(hostess.m_image, sofa.m_position.x, sofa.m_position.y, WHITE);
	hostess.m_position = sofa.m_position;
	hostess.m_position.y -= 50;
	hostess.Draw();
}

void Game::InitGame()
{
	std::cout << "GAME STARTED!\n";
	m_sofas = CreateSofas();
	std::cout << m_sofas.size();
}

std::vector<Sofa> Game::CreateSofas()
{
	int offsetX = 150;
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


