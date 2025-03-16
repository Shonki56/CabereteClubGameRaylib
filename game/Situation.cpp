#include "Situation.hpp"

Situation::Situation()
{
	assignSituationType();
}

void Situation::Draw()
{
	DrawTexture(m_sofa, 500, 500, WHITE);
	
}

void Situation::setClientAndHostess(Client* client, Hostess* hostess)
{
	m_pClient = client;
	m_pHostess = hostess;
}

void Situation::assignSituationType()
{
	int random = GetRandomValue(0, 3);
	m_sitType = static_cast<SituationType>(random);
	situationName = situationNames[random];
}
