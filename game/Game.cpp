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
		
		if (CheckCollisionPointRec(GetMousePosition(), sofa.m_area) && sofa.m_isBeingUsedByClient == true && isAHostessCurrentlySelected() == true)
		{
			GUI::showHostessAndClientStats(selectedHostess, sofa.m_currentClient);
			GUI::showComparison(selectedHostess, sofa.m_currentClient);
			//std::cout << sofa.m_currentClient->m_happiness << std::endl;
		}
	}

	for (auto& hostess : m_hostesses)
	{
		hostess.Draw();
	}

	for (auto& client : m_clients)
	{
		client->Draw();
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
		spawnClient();
	}

	removeClient();

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
	initHostesses();
	m_lastSpawnTime = 0.0f;
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
				std::cout << hostess.m_name << " is currently " << (hostess.m_isCurrentlySelected ? "" : "NOT ") << "selected\n";
			}
				

		}
	}
}

void Game::initHostesses()
{
	m_hostesses[0].m_image = LoadTexture("resources/Images/fullBodyGirls/Angelica.png");
	m_hostesses[0].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Angelica-Head.png");
	m_hostesses[0].m_stats = { 100,40,23,11,51 };
	m_hostesses[0].m_traits = { 10,10,10,10 };
	m_hostesses[0].m_name = "Angel";

	m_hostesses[1].m_image = LoadTexture("resources/Images/fullBodyGirls/Clara.png");
	m_hostesses[1].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Clara-Head.png");
	m_hostesses[1].m_stats = { 200,10,10,10,10 };
	m_hostesses[1].m_traits = { 30,33,70,62 };
	m_hostesses[1].m_name = "Clara";
}

bool Game::isAHostessCurrentlySelected()
{
	for (auto& hostess : m_hostesses)
	{
		if (hostess.m_isCurrentlySelected == true)
		{
			selectedHostess = hostess;
			return true;

		}
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
					if (!m_sofas[i].m_isBeingUsed && m_hostesses[j].m_isCurrentlySelected && m_hostesses[j].m_isBeingUsed == false && m_sofas[i].m_currentClient != nullptr)
					{
						std::cout << m_hostesses[j].m_name << " is sitting on sofa number " << i << std::endl;
						placeHostess(m_hostesses[j], m_sofas[i]);
					}
					else if (m_sofas[i].m_isBeingUsed && m_sofas[i].m_currentHostess == &m_hostesses[j])
					{
						m_sofas[i].m_isBeingUsed = false;
						m_hostesses[j].m_isBeingUsed = false;
						m_sofas[i].m_currentHostess = nullptr;
						std::cout << m_hostesses[j].m_name << " has been taken off sofa number " << i << std::endl;
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





// CLIENT STUFF

void Game::generateClient()
{
	const float spawnTime = 8.0f;
	float currentTime = GetTime();
	if (currentTime - m_lastSpawnTime >= spawnTime)
	{
		spawnClient();
		m_lastSpawnTime = currentTime;
	}
}

void Game::spawnClient()
{
	auto client = std::make_unique<Client>(POOR);

	placeClient(*client);
	m_clients.push_back(std::move(client));
}

int Game::checkIfSofaIsFree() 
{
	for (int i = 0; i < m_sofas.size(); i++)
	{
		if (m_sofas[i].m_currentClient == nullptr)
		{
			return i;
			break;
		}
		else
		{
			std::cout << "Sofa " << i << " is currently being used\n";
		}

	}

	std::cout << "No free sofa found!\n";
	return -1;


}

bool Game::clientTimeout(const Client& client)
{
	float currentTime = GetTime();
	if (currentTime - client.m_timeSpawnedIn >= client.m_timeout)
	{
		return true;
	}

	return false;
}

void Game::removeClient()
{
	for (int i = m_clients.size() - 1; i >= 0; i--)
	{
		if (clientTimeout(*m_clients[i]))
		{
			Client* clientPtr = m_clients[i].get();
			auto it = m_clientSofaMap.find(clientPtr);
			if (it != m_clientSofaMap.end())
			{
				int sofaIndex = it->second;
				m_sofas[sofaIndex].m_currentClient = nullptr;
				m_clientSofaMap.erase(it);
				m_sofas[sofaIndex].m_isBeingUsedByClient = false;
				std::cout << "Client removed. Sofa " << sofaIndex << " is now free!\n";
			}
			m_clients.erase(m_clients.begin() + i);
			
		}
	}
}

void Game::placeClient(Client& client)
{
	if (checkIfSofaIsFree() != -1)
	{
		int sofaNotBeingUsed = checkIfSofaIsFree();

		client.m_position.y = m_sofas[sofaNotBeingUsed].m_position.y;
		client.m_position.x = m_sofas[sofaNotBeingUsed].m_position.x + 100;
		client.m_isSeated = true;


		m_sofas[sofaNotBeingUsed].m_currentClient = &client;
		m_sofas[sofaNotBeingUsed].m_isBeingUsedByClient = true;

		m_clientSofaMap[&client] = sofaNotBeingUsed;

		std::cout << "Client pointer " << &client << " added to map with sofa index " << sofaNotBeingUsed << std::endl;


		std::cout << "Client placed on sofa: " << sofaNotBeingUsed << std::endl;

	}
}





