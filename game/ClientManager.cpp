#include "ClientManager.hpp"

void ClientManager::spawnClient()
{
	auto client = std::make_unique<Client>(POOR);

	placeClient(*client);
	m_clients.push_back(std::move(client));
}

void ClientManager::generateClient()
{
	const float spawnTime = 8.0f;
	float currentTime = GetTime();
	if (currentTime - m_lastClientSpawnTime >= spawnTime)
	{
		spawnClient();
		m_lastClientSpawnTime = currentTime;
	}
}

void ClientManager::placeClient(Client& client)
{
	int sofaNotBeingUsed = m_sofaManager.checkIfASofaIsFree();
	if (sofaNotBeingUsed != -1)
	{
		client.m_position.y = m_sofaManager.m_sofas[sofaNotBeingUsed].m_position.y;

		client.m_position.x = m_sofaManager.m_sofas[sofaNotBeingUsed].m_position.x + 100;

		client.m_isSeated = true;

		m_sofaManager.m_sofas[sofaNotBeingUsed].m_currentClient = &client;
		m_sofaManager.m_sofas[sofaNotBeingUsed].m_isBeingUsedByClient = true;

		
		m_clientSofaMap[&client] = sofaNotBeingUsed;

		std::cout << "Client pointer " << &client << " added to map with sofa index " << sofaNotBeingUsed << std::endl;


		std::cout << "Client placed on sofa: " << sofaNotBeingUsed << std::endl;

	}
	else
	{
		std::cout << "Unable to place client because m_sofaManager.CheckIfASofaIsFree == " << m_sofaManager.checkIfASofaIsFree() << std::endl;
	}
}

void ClientManager::removeClient()
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
				m_sofaManager.m_sofas[sofaIndex].m_currentClient = nullptr;
				m_clientSofaMap.erase(it);
				m_sofaManager.m_sofas[sofaIndex].m_isBeingUsedByClient = false;
				
				std::cout << "Client removed. Sofa " << sofaIndex << " is now free!\n";
			}
			m_clients.erase(m_clients.begin() + i);
			
		}
	}

}

bool ClientManager::isClientTimedOut(const Client& client)
{
	float currentTime = GetTime();
	if (currentTime - client.m_timeSpawnedIn >= client.m_timeout)
	{
		return true;
	}

	return false;
}
