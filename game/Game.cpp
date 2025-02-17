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

}

void Game::HandleInputs()
{
	// Place hostess thing in here???
	// Holy shit, it works!!! Halfly...
	for (auto& sofa : m_sofas)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePosition = GetMousePosition();
			if (CheckCollisionPointRec(mousePosition, sofa.m_area))
			{
				if (!sofa.m_isBeingUsed)
				{
					sofa.ChangeToActive();
					std::cout << "Now True!\n";
					// Need to make a selected hostess thing
					placeHostess(m_hostesses[0], sofa);
					m_hostesses[0].m_isBeingUsed = true;
				}
				else
				{
					sofa.m_isBeingUsed = false;
					std::cout << "Now False!\n";
					m_hostesses[0].m_isBeingUsed = false;
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
	CreateHostesses();
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

void Game::CreateHostesses()
{
    Hostess test;
    Traits testTraits = { 10,10,10,10 };
    Stats testStats = { 100, 10,10,10,10 };
    test.stats = testStats;
    test.traits = testTraits;
    Texture2D woman = LoadTexture("resources/Images/Angel/Angelica-Human4_B.png");
    test.m_image = woman;
	m_hostesses.push_back(test);
}


