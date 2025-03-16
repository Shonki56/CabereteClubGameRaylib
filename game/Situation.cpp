#include "Situation.hpp"

Situation::Situation()
{
	assignSituationType();
	
}

void Situation::Draw()
{
	DrawTexture(m_sofa, 500, 500, WHITE);
	//DrawTexture(m_pClient->m_clientImage, 600, 500, WHITE);
	DrawTextureEx(m_pClient->m_clientImage, m_clientPosition, 0, m_pClient->m_textureScale, WHITE);
	DrawTextureEx(m_pHostess->m_image, m_hostessPosition, 0, m_pHostess->m_textureScale, WHITE);
}

void Situation::setClientAndHostess(Client* client, Hostess* hostess)
{
	Client* clientCopy = new Client(*client);
	m_pClient = clientCopy;


	Hostess* hostessCopy = new Hostess(*hostess);
	m_pHostess = hostessCopy;

}

void Situation::assignSituationType()
{
	int random = GetRandomValue(0, 3);
	m_sitType = static_cast<SituationType>(random);
	situationName = situationNames[random];
}
