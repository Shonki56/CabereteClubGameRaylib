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

	m_clientManager.removeClient(m_sofaManager);
	m_gameTimer.updateCurrentTimeAndTimeLeft();
	GUI::showTimer(m_gameTimer.getTimeLeft());

	if (m_currentSituation != nullptr)
	{
		if (m_currentSituation->m_isSituationOver) // dont think im resetting the sofas m_currentSituation
		{
			delete m_currentSituation;
			m_currentGameState = MAIN_GAME;
			m_currentSituation = nullptr;
			continueAllTimers(); // this causing the extra seconds added to timer
		}
	}
	

	if (isFeverTimeActive == true)
	{
		if (m_clientManager.isThereCurrentlyAFeverTimeClient() == false)
		{
			isFeverTimeActive = false;
		}

	}

	if (isFeverTimeActive == false)
	{
		m_sofaManager.createSituationsForSofas();
	}
}

void Game::HandleInputs()
{
	m_hostessManager.handlePlacingHostesses(m_sofaManager);
	m_hostessManager.handleSelectingHostesses();

	for (Sofa& sofa : m_sofaManager.m_sofas)
	{
		if (CheckCollisionPointRec(GetMousePosition(), sofa.m_area) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && sofa.m_currentSituation != nullptr)
		{
			m_currentSituation = sofa.m_currentSituation;
			m_currentGameState = SITUATION;
			sofa.m_currentClient->m_hasHadSituation = true;
			pauseAllTimers();
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

void Game::clientGiveMoneyAndAddToFeverTime(Hostess* hostess, Client* client)
{
	float howMuchToAdd = client->m_howMuchToSpend();
	hostess->m_moneyMade += howMuchToAdd;
	addToFeverTimeMeter(howMuchToAdd / 1000.0);
	std::cout << "This is in Game::clientGiveMoney \t Client total time remaining: " << client->m_spendMoneyTimer.getTotalTime() << std::endl;
	std::cout << "This is in Game::clientGiveMoney \t Client happiness level: " << client->m_happiness << std::endl;
	std::cout << howMuchToAdd / 1000.0 << "Has been added to fever time meter\n";
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
			clientGiveMoneyAndAddToFeverTime(sofa.m_currentHostess, sofa.m_currentClient);
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

	drawFeverTimeProgressBar();
}

void Game::drawCurrentSituation()
{
	m_currentSituation->Draw();
}

void Game::pauseAllTimers()
{
	for (auto& client : m_clientManager.m_clients)
	{
		Client& ptrclient = *client;

		ptrclient.pauseTimers();
	}

	m_gameTimer.pauseTimer();
}

void Game::continueAllTimers()
{
	for (auto& client : m_clientManager.m_clients)
	{
		Client& ptrclient = *client;

		ptrclient.continueTimers();
	}

	m_gameTimer.continueTimer();
}

void Game::endSituation()
{

}

void Game::addToFeverTimeMeter(float amountToAdd)
{
	if (isFeverTimeActive == false)
	{
		m_feverTimeLevel += amountToAdd;
	}
}

void Game::drawFeverTimeProgressBar()
{
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SIZE, 14);
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SPACING, 1);
	Rectangle progressBarRectangle{ 100, 800, 200, 30 }; 
	Rectangle feverTimeButton{ 350, 800, 100, 30 };
	GuiProgressBar(progressBarRectangle, "FEVER TIME", "", &m_feverTimeLevel, 0, 100);
	if (GuiButton(feverTimeButton, "Fever Time!"))
	{
		if (m_feverTimeLevel >= 100)
		{
			activateFeverTime();
		}
	}
}

void Game::activateFeverTime()
{
	isFeverTimeActive = true;
	m_feverTimeLevel = 0;
	m_clientManager.extendTimers();
	m_sofaManager.clearAllSituations();
	m_clientManager.applyFeverTime(); 
}

