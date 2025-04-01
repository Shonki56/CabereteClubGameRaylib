#pragma once
#include "raylib.h"
#include <string>
#include "Client.hpp"
#include "Hostess.hpp"
#include "include/raygui.h"

class Situation
{
public:
	enum SituationType {DEFAULT, SMALL_GLASS, BIG_GLASS, TOWEL, MENU};
	Client* m_pClient;
	Hostess* m_pHostess;
	Texture2D m_sofaTexture = LoadTexture("resources/Images/sofa.png");
	SituationType m_sitType;
	std::string situationNames[5] = {"", "Small Glass", "Big Glass", "Towel", "Menu" };
	std::string situationName;
	Vector2 m_sofaPosition = { 400, 500 };
	Vector2 m_clientPosition = { m_sofaPosition.x + 450, m_sofaPosition.y};
	Vector2 m_hostessPosition = { m_sofaPosition.x + 150, m_sofaPosition.y - 50};
	SituationType m_playerChoice = DEFAULT;
	Rectangle m_hostessNeed{843, 400, 100, 100};
	Texture2D m_hostessNeddTexture;
	bool m_isSituationOver = false;
	void showChoicesAndSetPlayerChoice();
	void setClientAndHostess(Client* client, Hostess* hostess);
	Situation();
	Situation(Client* client, Hostess* hostess);
	void Draw();
private:
	void assignSituationType();
	void answerChecker();
	void setHostessNeedTexture();
	void improveHappiness();

};
