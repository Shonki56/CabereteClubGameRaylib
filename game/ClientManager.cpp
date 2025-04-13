#include "ClientManager.hpp"

void ClientManager::spawnClient(SofaManager& sofaManager)
{
	auto client = std::make_unique<Client>(MEGARICH);

	placeClient(*client, sofaManager);
	m_clients.push_back(std::move(client));
}

void ClientManager::applyFeverTime()
{
	for (auto& client : m_clients)
	{
		client->setHappiness(SPECIAL);
	}
}

void ClientManager::extendTimers()
{
	for (auto& client : m_clients)
	{
		client->m_lifetimeTimer.extendTimer(50); // temp value to see if it works
		std::cout << "Client time is now: " << client->m_lifetimeTimer.getTimeLeft() << std::endl;
	}
}

void ClientManager::generateClient(SofaManager& sofaManager)
{
	const float spawnTime = 3.0f;
	float currentTime = GetTime();
	if (currentTime - m_lastClientSpawnTime >= spawnTime)
	{
		spawnClient(sofaManager);
		m_lastClientSpawnTime = currentTime;
	}
}



void ClientManager::placeClient(Client& client, SofaManager& sofaManager)
{
	int sofaNotBeingUsed = sofaManager.checkIfASofaIsFree();
	if (sofaNotBeingUsed != -1)
	{
		client.m_position.y = sofaManager.m_sofas[sofaNotBeingUsed].m_position.y;

		client.m_position.x = sofaManager.m_sofas[sofaNotBeingUsed].m_position.x + 100;

		client.m_isSeated = true;

		sofaManager.m_sofas[sofaNotBeingUsed].m_currentClient = &client;
		sofaManager.m_sofas[sofaNotBeingUsed].m_isBeingUsedByClient = true;

		
		m_clientSofaMap[&client] = sofaNotBeingUsed;

		std::cout << "Client pointer " << &client << " added to map with sofa index " << sofaNotBeingUsed << std::endl;


		std::cout << "Client placed on sofa: " << sofaNotBeingUsed << std::endl;

	}
	else
	{
		std::cout << "Unable to place client because m_sofaManager.CheckIfASofaIsFree == " << sofaManager.checkIfASofaIsFree() << std::endl;
	}
}

void ClientManager::removeClient(SofaManager& sofaManager)
{
	for (int i = m_clients.size() - 1; i >= 0; i--)
	{
		if (isClientTimedOut(*m_clients[i]))
		{
			Client* clientPtr = m_clients[i].get();
			auto it = m_clientSofaMap.find(clientPtr);
			if (it != m_clientSofaMap.end())
			{
				int sofaIndex = it->second;
				sofaManager.m_sofas[sofaIndex].m_currentClient = nullptr;
				m_clientSofaMap.erase(it);
				sofaManager.m_sofas[sofaIndex].m_isBeingUsedByClient = false;
				
				std::cout << "Client removed. Sofa " << sofaIndex << " is now free!\n";
			}
			m_clients.erase(m_clients.begin() + i);
			
		}
	}

}

bool ClientManager::isClientTimedOut(const Client& client)
{
	if (client.m_lifetimeTimer.m_hasTimerRunOut)
	{
		return true;
	}

	return false;
}
