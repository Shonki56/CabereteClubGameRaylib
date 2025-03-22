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
	Situation();
	void Draw();
	Client* m_pClient;
	Hostess* m_pHostess;
	Texture2D m_sofaTexture = LoadTexture("resources/Images/sofa.png");
	SituationType m_sitType;
	std::string situationNames[5] = {"", "Small Glass", "Big Glass", "Towel", "Menu" };
	std::string situationName;
	void setClientAndHostess(Client* client, Hostess* hostess);
	Vector2 m_sofaPosition = { 400, 500 };
	Vector2 m_clientPosition = { m_sofaPosition.x + 450, m_sofaPosition.y};
	Vector2 m_hostessPosition = { m_sofaPosition.x + 150, m_sofaPosition.y - 50};
	SituationType m_playerChoice = DEFAULT;
	void showChoicesAndSetPlayerChoice();
	bool m_isSituationOver = false;
	Rectangle m_hostessNeed{843, 400, 100, 100};
	Texture2D m_hostessNeddTexture;
private:
	void assignSituationType();
	void answerChecker();
	void setHostessNeedTexture();

};
