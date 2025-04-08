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
#include "Situation.hpp"



class Game
{
public:
	enum GameState {MAIN_GAME, SITUATION, FEVER_TIME};
	Game();
	void Draw();
	void Update();
	void HandleInputs();
	void playGame();
	float m_lastSpawnTime;
	float m_timePerNight = 20.0f;
	Timer m_gameTimer;
	HostessManager m_hostessManager;
	unsigned int m_moneyMade;
	GameState m_currentGameState = MAIN_GAME;
private:
	void InitGame();
	void displayHostessesFaces();
	void clientGiveMoneyAndAddToFeverTime(Hostess* hostess, Client* client);
	SofaManager m_sofaManager;
	ClientManager m_clientManager;
	Situation* m_currentSituation = nullptr;
	void createSituation();
	void drawMainGame();
	void drawCurrentSituation();
	void pauseAllTimers();
	void continueAllTimers();
	void endSituation();
	float m_feverTimeLevel = 0;
	void addToFeverTimeMeter(float);
	void drawFeverTimeProgressBar();
};
