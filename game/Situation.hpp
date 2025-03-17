#pragma once
#include "raylib.h"
#include <string>
#include "Client.hpp"
#include "Hostess.hpp"
#include "GUI.hpp"
#include "include/raygui.h"

class Situation
{
public:
	enum SituationType {SMALL_GLASS, BIG_GLASS, TOWEL, MENU};
	Situation();
	void Draw();
	Client* m_pClient;
	Hostess* m_pHostess;
	Texture2D m_sofa = LoadTexture("resources/Images/sofa.png");
	SituationType m_sitType;
	std::string situationNames[4] = { "Small Glass", "Big Glass", "Towel", "Menu" };
	std::string situationName;
	void setClientAndHostess(Client* client, Hostess* hostess);
	Vector2 m_sofaPosition = { 400, 500 };
	Vector2 m_clientPosition = { m_sofaPosition.x + 450, m_sofaPosition.y};
	Vector2 m_hostessPosition = { m_sofaPosition.x + 150, m_sofaPosition.y - 50};
	void displayAndSetPlayerAnswer();
	SituationType m_playerAnswer;
private:
	void assignSituationType();

};
