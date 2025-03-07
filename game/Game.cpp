#include "Game.hpp"
#include <iostream>
#include "include/stb_image_write.h"

Game::Game()
{
	InitGame();
}

void Game::playGame()
{
	Draw();
	Update();
}

void Game::Draw()
{
	for (auto& sofa : m_sofaManager.m_sofas)
	{
		sofa.Draw();
		
		if (CheckCollisionPointRec(GetMousePosition(), sofa.m_area) && sofa.m_isBeingUsedByClient == true && m_hostessManager.isAHostessCurrentlySelected() == true)
		{
			GUI::showHostessAndClientStats(m_hostessManager.m_selectedHostess, sofa.m_currentClient);
			GUI::showComparison(m_hostessManager.m_selectedHostess, sofa.m_currentClient);
		}

		if (sofa.m_isBeingUsed && sofa.m_isBeingUsedByClient)
		{
			clientGiveMoney(sofa.m_currentHostess, sofa.m_currentClient);
		}

		GUI::showMoneyEarnedByHostesses(m_hostessManager.m_hostesses);

	}

	for (auto& hostess : m_hostessManager.m_hostesses)
	{
		hostess.Draw();
	}

	for (auto& client : m_clientManager.m_clients)
	{
		client->Draw();
	}
}

void Game::Update()
{
	HandleInputs();
	displayHostessesFaces();
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
	{
		std::cout << "Mouse X Pos:" << GetMousePosition().x << std::endl;
		std::cout << "Mouse Y Pos:" << GetMousePosition().y << std::endl;
	}

	if (m_clients.size() < 4)
	{
		//generateClient();
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
	{
		m_clientManager.spawnClient(m_sofaManager);
	}

	m_clientManager.removeClient(m_sofaManager);
	getTimeRemaining();

}

void Game::HandleInputs()
{
	m_hostessManager.handlePlacingHostesses(m_sofaManager);
	m_hostessManager.handleSelectingHostesses();
}

void Game::InitGame()
{
	m_lastSpawnTime = 0.0f;
}

void Game::getTimeRemaining()
{
	float currentTime = GetTime();
	m_timeRemaining = totalTimePerNight - currentTime;
	GUI::showTimer(m_timeRemaining);
}

bool Game::isNightOver()
{
	if (m_timeRemaining <= 0.0)
	{
		return true;
	}

	return false;
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

// CLIENT STUFF

//void Game::generateClient()
//{
//	const float spawnTime = 8.0f;
//	float currentTime = GetTime();
//	if (currentTime - m_lastSpawnTime >= spawnTime)
//	{
//		spawnClient();
//		m_lastSpawnTime = currentTime;
//	}
//}
//
//void Game::spawnClient()
//{
//	auto client = std::make_unique<Client>(POOR);
//
//	placeClient(*client);
//	m_clients.push_back(std::move(client));
//}
//
//bool Game::clientTimeout(const Client& client)
//{
//	float currentTime = GetTime();
//	if (currentTime - client.m_timeSpawnedIn >= client.m_timeout)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//void Game::removeClient()
//{
//	for (int i = m_clients.size() - 1; i >= 0; i--)
//	{
//		if (clientTimeout(*m_clients[i]))
//		{
//			Client* clientPtr = m_clients[i].get();
//			auto it = m_clientSofaMap.find(clientPtr);
//			if (it != m_clientSofaMap.end())
//			{
//				int sofaIndex = it->second;
//				m_sofaManager.m_sofas[sofaIndex].m_currentClient = nullptr;
//				m_clientSofaMap.erase(it);
//				m_sofaManager.m_sofas[sofaIndex].m_isBeingUsedByClient = false;
//				
//				std::cout << "Client removed. Sofa " << sofaIndex << " is now free!\n";
//			}
//			m_clients.erase(m_clients.begin() + i);
//			
//		}
//	}
//}
//
//
//void Game::placeClient(Client& client)
//{
//	if (m_sofaManager.checkIfASofaIsFree() != -1)
//	{
//		int sofaNotBeingUsed = m_sofaManager.checkIfASofaIsFree();
//
//		client.m_position.y = m_sofaManager.m_sofas[sofaNotBeingUsed].m_position.y;
//		client.m_position.x = m_sofaManager.m_sofas[sofaNotBeingUsed].m_position.x + 100;
//		client.m_isSeated = true;
//
//
//		m_sofaManager.m_sofas[sofaNotBeingUsed].m_currentClient = &client;
//		m_sofaManager.m_sofas[sofaNotBeingUsed].m_isBeingUsedByClient = true;
//
//		m_clientSofaMap[&client] = sofaNotBeingUsed;
//
//		std::cout << "Client pointer " << &client << " added to map with sofa index " << sofaNotBeingUsed << std::endl;
//
//
//		std::cout << "Client placed on sofa: " << sofaNotBeingUsed << std::endl;
//
//	}
//	else
//	{
//		std::cout << "Unable to place client because m_sofaManager.CheckIfASofaIsFree == " << m_sofaManager.checkIfASofaIsFree() << std::endl;
//	}
//}

// MAIN GAME LOGIC STUFF

void Game::clientGiveMoney(Hostess* hostess, Client* client)
{
	float currentTime = GetTime();
	if (currentTime - client->m_timeSinceLastSpentMoney >= client->m_howOftenToSpendMoney)
	{
		GameLogic::clientSpendMoney(hostess, client);
		client->m_timeSinceLastSpentMoney = currentTime;
	}

}
