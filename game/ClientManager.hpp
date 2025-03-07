#pragma once
#include <raylib.h>
#include "SofaManager.hpp"
#include "Client.hpp"
#include <vector>
#include <map>

class ClientManager
{
public:
	void generateClient();
	void placeClient(Client& client);
	void removeClient();
	bool isClientTimedOut(const Client& client);
	void spawnClient();
	float m_lastClientSpawnTime; 
	std::vector<std::unique_ptr<Client>> m_clients;
	std::map<Client*, int> m_clientSofaMap;
	SofaManager m_sofaManager;
private:
};
