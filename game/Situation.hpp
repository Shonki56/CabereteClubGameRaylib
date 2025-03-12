#pragma once
#include "Client.hpp"
#include "Hostess.hpp"
#include "Sofa.h"
#include <string>

class Situation
{
public:
	enum SituationType {SMALL_GLASS, BIG_GLASS, TOWEL, MENU};
	Situation(Hostess* hostess, Client* client, Sofa sofa) : m_hostess(hostess) , m_client(client), m_sofa(sofa) {}
	SituationType m_situation;
	Hostess* m_hostess;
	Client* m_client;
	Sofa m_sofa;
	void DrawSituation();
	std::string situationNames[4] = { "Small Glass", "Big Glass", "Towel", "Menu" };
	Timer m_timer;
private:
	void generateSituationType();


};
