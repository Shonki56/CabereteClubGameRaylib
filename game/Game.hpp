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
#include "Situation.hpp";



class Game
{
public:
	enum GameState {MAIN_GAME, SITUATION, CLIENT_LEAVING, FEVER_TIME};
	Game();
	void HandleInputs();
	void playGame();
	float m_lastSpawnTime;
	float m_timePerNight = 20.0f;
	Timer m_gameTimer;
	HostessManager m_hostessManager;
	unsigned int m_moneyMade;
	GameState m_gameState;
private:
	void InitGame();
	void displayHostessesFaces();
	void clientGiveMoney(Hostess* hostess, Client* client);
	SofaManager m_sofaManager;
	ClientManager m_clientManager;
	void DrawMainGame();
	void Draw();
	void Update();

};
