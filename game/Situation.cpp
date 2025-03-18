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
	showChoicesAndSetPlayerChoice();
}

void Situation::setClientAndHostess(Client* client, Hostess* hostess)
{
	Client* clientCopy = new Client(*client);
	m_pClient = clientCopy;


	Hostess* hostessCopy = new Hostess(*hostess);
	m_pHostess = hostessCopy;

}

void Situation::showChoicesAndSetPlayerChoice()
{
	Rectangle test{ 100, 200, 300, 430 };
	GuiGroupBox(test, "Choices");
	GuiSetStyle(GuiControl::BUTTON, GuiDefaultProperty::TEXT_SIZE, 32);
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SPACING, 8);
	Vector2 startPosition{ 100, 100 };
	Rectangle smallGlassRec{ test.x, test.y + 30, 300, 60 };
	Rectangle bigGlassRec{ test.x, test.y + 130, 300, 60 };
	Rectangle towelRec{ test.x, test.y + 230, 300, 60 };
	Rectangle menuRec{ test.x, test.y + 330, 300, 60 };
	if (GuiButton(smallGlassRec, situationNames[0].c_str()))
	{
		m_playerChoice = SMALL_GLASS;
	}
	if (GuiButton(bigGlassRec, situationNames[1].c_str()))
	{
		m_playerChoice = BIG_GLASS;
	}
	if (GuiButton(towelRec, situationNames[2].c_str()))
	{
		m_playerChoice = TOWEL;
	}
	if (GuiButton(menuRec, situationNames[3].c_str()))
	{
		m_playerChoice = MENU;
	}


}

void Situation::assignSituationType()
{
	int random = GetRandomValue(0, 3);
	m_sitType = static_cast<SituationType>(random);
	situationName = situationNames[random];
}
