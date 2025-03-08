#pragma once
#include <raylib.h>
#include <vector>
#include "raymath.h"
#include "lib.h"
#include "Gui.hpp"
#include "Client.hpp"
#include "GameLogic.hpp"
#include "HostessManager.hpp"
#include "SofaManager.hpp"
#include "ClientManager.hpp"
#include "Timer.hpp";



class Game
{
public:
	Game();
	void Draw();
	void Update();
	void HandleInputs();
	float m_lastSpawnTime;
	float m_timePerNight = 20.0f;
	void playGame();
	Timer m_gameTimer;
private:
	void InitGame();
	void displayHostessesFaces();
	void clientGiveMoney(Hostess* hostess, Client* client);
	HostessManager m_hostessManager;
	SofaManager m_sofaManager;
	ClientManager m_clientManager;

};
