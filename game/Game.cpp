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
	// Place hostess thing in here???
	// Holy shit, it works!!! Halfly...
	// Update 19/02/25 - Fix this. Kind of works
	for (auto& sofa : m_sofas)
	{
		for (int i = 0; i < 2; i++)
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				Vector2 mousePosition = GetMousePosition();
				if (CheckCollisionPointRec(mousePosition, sofa.m_area))
				{
					if (!sofa.m_isBeingUsed && m_hostesses[i].m_isCurrentlySelected == true)
					{
						sofa.ChangeToActive();
						std::cout << "Now True!\n";
						// Need to make a selected hostess thing
						placeHostess(m_hostesses[i], sofa);
						m_hostesses[i].m_isBeingUsed = true;
						m_hostesses[i].m_isCurrentlySelected = false;
					}
					else
					{
						sofa.m_isBeingUsed = false;
						std::cout << "Now False!\n";
						//m_hostesses[i].m_isBeingUsed = false;
						m_hostesses[i].m_isCurrentlySelected = false;
					}
				}
			}

		}
	}

	for (auto& hostess : m_hostesses)
	{
		if (hostess.m_isBeingUsed == false)
		{
			Vector2 mousePosition = GetMousePosition();
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (CheckCollisionPointRec(mousePosition, hostess.m_faceImageRectangle))
				{
					if (hostess.m_isCurrentlySelected == false)
					{
						hostess.m_isCurrentlySelected = true;
						std::cout << hostess.m_isCurrentlySelected << std::endl;
					}
					else
					{
						hostess.m_isCurrentlySelected = false;
						std::cout << hostess.m_isCurrentlySelected << std::endl;
					}
				}
			}

		}
	}
}

void Game::placeHostess(Hostess& hostess, Sofa& sofa)
{
	hostess.m_position = sofa.m_position;
	hostess.m_position.y -= 50;
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

void Game::CreateHostesses()
{
    Hostess test;
    Traits testTraits = { 10,10,10,10 };
    Stats testStats = { 100, 10,10,10,10 };
    test.stats = testStats;
    test.traits = testTraits;
    Texture2D HostessFullBody = LoadTexture("resources/Images/Angel/Angelica-Human4_B.png");
	Texture2D hostessHead = LoadTexture("resources/Images/Angel/Angelica-Human4_B-Head.png");
	test.m_faceImage = hostessHead;
    test.m_image = HostessFullBody;
//	m_hostesses.push_back(test);
}

void Game::displayHostessesFaces()
{
	int count = 1;
	for (auto& hostess : m_hostesses)
	{
		if (hostess.m_isBeingUsed == false)
		{
			hostess.m_faceImagePosition = { float(count * 100), float(count * 50) };
			hostess.m_faceImageRectangle = hostess.getRect();
			DrawTexture(hostess.m_faceImage, count * 100, count * 50, WHITE);
			if (hostess.m_isCurrentlySelected == false)
			{
				DrawRectangleLines(count * 100, count * 50, hostess.m_faceImage.width, hostess.m_faceImage.height, WHITE);
			}
			else
				DrawRectangleLines(count * 100, count * 50, hostess.m_faceImage.width, hostess.m_faceImage.height, GREEN);
		}

		count++;
	}
}

void Game::initHostesses()
{
	//for (auto& hostess : m_hostesses)
	//{
	//	hostess = Hostess();
	//}

	m_hostesses[0].m_image = LoadTexture("resources/Images/fullBodyGirls/Angelica.png");
	m_hostesses[0].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Angelica-Head.png");
	m_hostesses[0].stats = { 100,10,10,10,10 };
	m_hostesses[0].traits = { 10,10,10,10 };

	m_hostesses[1].m_image = LoadTexture("resources/Images/fullBodyGirls/Clara.png");
	m_hostesses[1].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Clara-Head.png");
	m_hostesses[1].stats = { 100,10,10,10,10 };
	m_hostesses[1].traits = { 10,10,10,10 };
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


