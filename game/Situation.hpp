#pragma once
#include "raylib.h"
#include <string>
#include "Client.hpp"
#include "Hostess.hpp"

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


private:
	void assignSituationType();

};
