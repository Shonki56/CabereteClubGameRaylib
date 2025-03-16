#include "Game.hpp"
#include <iostream>
#include "include/stb_image_write.h"

Game::Game()
{
	InitGame();
}

void Game::playGame()
{
	Update();
	Draw();
}

void Game::Draw()
{
	switch (m_currentGameState)
	{
	case MAIN_GAME:
		drawMainGame();
		break;
	case SITUATION:
		drawCurrentSituation();
		break;
	}
}

void Game::Update()
{
	m_sofaManager.freeEmptySofas();
	HandleInputs();
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
	{
		std::cout << "Mouse X Pos:" << GetMousePosition().x << std::endl;
		std::cout << "Mouse Y Pos:" << GetMousePosition().y << std::endl;
	}

	//if (m_clients.size() < 4)
	//{
	//	//generateClient();
	//}

	if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
	{
		m_clientManager.spawnClient(m_sofaManager);
	}

	if (IsKeyPressed(KEY_T))
	{
		createSituation();
	}

	if (IsKeyPressed(KEY_C))
	{
		if (m_gameTimer.m_currentState == Timer::TimerState::NOT_PAUSED)
		{
			m_gameTimer.pauseTimer();
		}
		else
		{
			m_gameTimer.continueTimer();
		}
	}

	m_clientManager.removeClient(m_sofaManager);
	m_gameTimer.updateCurrentTimeAndTimeLeft();
	GUI::showTimer(m_gameTimer.getTimeLeft());

}

void Game::HandleInputs()
{
	m_hostessManager.handlePlacingHostesses(m_sofaManager);
	m_hostessManager.handleSelectingHostesses();

	for (int i = 0; i < 4; i++)
	{

	}

	for (Sofa& sofa : m_sofaManager.m_sofas)
	{
		if (CheckCollisionPointRec(GetMousePosition(), sofa.m_area) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && sofa.m_currentSituation != nullptr)
		{
			m_currentSituation = sofa.m_currentSituation;
			m_currentGameState = SITUATION;
		}
	}
}

void Game::InitGame()
{
	m_lastSpawnTime = 0.0f;
}


// HOSTESS STUFF

void Game::displayHostessesFaces()
{
	int count = 1;
	for (auto& hostess : m_hostessManager.m_hostesses)
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


// MAIN GAME LOGIC STUFF

void Game::clientGiveMoney(Hostess* hostess, Client* client)
{
	hostess->m_moneyMade += client->m_howMuchToSpend();
	std::cout << hostess->m_name << " has just made some money!\n";
}

// Situation stuff

void Game::createSituation()
{
	for (Sofa& sofa : m_sofaManager.m_sofas)
	{
		if (sofa.m_isBeingUsed  && sofa.m_currentSituation == nullptr)
		{
			sofa.m_currentSituation = new Situation();
			sofa.m_currentSituation->setClientAndHostess(sofa.m_currentClient, sofa.m_currentHostess);
			std::cout << sofa.m_currentSituation->situationName << std::endl;
			return;
		}
	}
}

void Game::drawMainGame()
{
	for (auto& sofa : m_sofaManager.m_sofas)
	{
		sofa.Draw();
		
		if (CheckCollisionPointRec(GetMousePosition(), sofa.m_area) && sofa.m_isBeingUsedByClient == true && m_hostessManager.isAHostessCurrentlySelected() == true)
		{
			GUI::showHostessAndClientStats(m_hostessManager.m_selectedHostess, sofa.m_currentClient);
			GUI::showComparison(m_hostessManager.m_selectedHostess, sofa.m_currentClient);
		}

		if (sofa.m_isBeingUsed && sofa.m_isBeingUsedByClient && sofa.m_currentClient->m_spendMoneyTimer.m_hasTimerRunOut)
		{
			clientGiveMoney(sofa.m_currentHostess, sofa.m_currentClient);
			sofa.m_currentClient->m_spendMoneyTimer.resetTimer();
		}
	}

	for (auto& hostess : m_hostessManager.m_hostesses)
	{
		hostess.Draw();
	}

	for (auto& client : m_clientManager.m_clients)
	{
		client->DrawAndUpdate();
	}

	displayHostessesFaces();
}

void Game::drawCurrentSituation()
{
	m_currentSituation->Draw();
}

