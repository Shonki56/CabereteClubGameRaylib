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
	displayAndSetPlayerAnswer();
}

void Situation::setClientAndHostess(Client* client, Hostess* hostess)
{
	Client* clientCopy = new Client(*client);
	m_pClient = clientCopy;


	Hostess* hostessCopy = new Hostess(*hostess);
	m_pHostess = hostessCopy;

}

void Situation::displayAndSetPlayerAnswer()
{
	Vector2 startPos = {114, 96};
	Rectangle menuRec{ startPos.x, startPos.y + 100, 300, 50};
	if (GuiButton(menuRec, situationNames[0].c_str()))
	{
		m_playerAnswer = SMALL_GLASS;
	}

	Rectangle OtherRec{ startPos.x, startPos.y + 200, 300, 50};
	if (GuiButton(OtherRec, situationNames[1].c_str()))
	{
		m_playerAnswer = BIG_GLASS;
	}

	Rectangle OtherRec2{ startPos.x, startPos.y + 300, 300, 50};
	if (GuiButton(OtherRec2, situationNames[2].c_str()))
	{
		m_playerAnswer = TOWEL;
	}

	Rectangle OtherRec3{ startPos.x, startPos.y + 400, 300, 50};
	if (GuiButton(OtherRec3, situationNames[3].c_str()))
	{
		m_playerAnswer = MENU;
	}
}

void Situation::assignSituationType()
{
	int random = GetRandomValue(0, 3);
	m_sitType = static_cast<SituationType>(random);
	situationName = situationNames[random];
}
