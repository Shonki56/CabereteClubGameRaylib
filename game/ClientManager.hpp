#pragma once
#include <raylib.h>
#include "SofaManager.hpp"
#include "Client.hpp"
#include <vector>
#include <map>

class ClientManager
{
public:
	void generateClient(SofaManager& sofaManager);
	void placeClient(Client& client, SofaManager& sofaManager);
	void removeClient(SofaManager& sofaManager);
	bool isClientTimedOut(const Client& client);
	void spawnClient(SofaManager& sofaManager);
	float m_lastClientSpawnTime; 
	std::vector<std::unique_ptr<Client>> m_clients;
	std::map<Client*, int> m_clientSofaMap;
	void applyFeverTime();
	void extendTimers();
	bool isThereCurrentlyAFeverTimeClient();
	bool m_feverTimeClientActive = false;
private:
};
