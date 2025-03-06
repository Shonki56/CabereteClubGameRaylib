#pragma once
#include <raylib.h>
#include <Sofa.h>
#include <vector>
#include <Hostess.hpp>
#include "raymath.h"
#include "lib.h"
#include "Gui.hpp"
#include "Client.hpp"
#include "GameLogic.hpp"
#include <map>
#include <iterator>
#include "HostessManager.hpp"



class Game
{
public:
	Game();
	void Draw();
	void Update();
	void HandleInputs();
	std::vector<Sofa> m_sofas;
	void placeClient(Client& client);
	float m_lastSpawnTime;
	void playGame();
	void getTimeRemaining();
	bool isNightOver();
private:
	void InitGame();
	std::vector<Sofa> CreateSofas();
	const float totalTimePerNight = 20.0f;
	float m_timeRemaining = totalTimePerNight;
	Hostess m_hostesses[2];
	Hostess selectedHostess;
	void displayHostessesFaces();
	void handlePlacingHostess();
	void generateClient();
	void spawnClient();
	std::vector<std::unique_ptr<Client>> m_clients;
	int checkIfSofaIsFree();
	bool clientTimeout(const Client& client);
	void removeClient();
	std::map<Client*, int> m_clientSofaMap;
	void clientGiveMoney(Hostess* hostess, Client* client);
	HostessManager m_hostessManager;

};
