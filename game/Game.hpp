#pragma once
#include <raylib.h>
#include <vector>
#include "raymath.h"
#include "lib.h"
#include "Gui.hpp"
#include "Client.hpp"
#include "GameLogic.hpp"
#include <map>
#include <iterator>
#include "HostessManager.hpp"
#include "SofaManager.hpp"
#include "ClientManager.hpp"



class Game
{
public:
	Game();
	void Draw();
	void Update();
	void HandleInputs();
	void placeClient(Client& client);
	float m_lastSpawnTime;
	void playGame();
	void getTimeRemaining();
	bool isNightOver();
private:
	void InitGame();
	const float totalTimePerNight = 20.0f;
	float m_timeRemaining = totalTimePerNight;
	void displayHostessesFaces();
	void generateClient();
	void spawnClient();
	std::vector<std::unique_ptr<Client>> m_clients;
	bool clientTimeout(const Client& client);
	void removeClient();
	std::map<Client*, int> m_clientSofaMap;
	void clientGiveMoney(Hostess* hostess, Client* client);
	HostessManager m_hostessManager;
	SofaManager m_sofaManager;
	ClientManager m_clientManager;

};
