#include "Situation.hpp"

Situation::Situation()
{
	assignSituationType();
	
}

void Situation::Draw()
{
	DrawTexture(m_sofaTexture, 500, 500, WHITE);
	DrawTextureEx(m_pClient->m_clientImage, m_clientPosition, 0, m_pClient->m_textureScale, WHITE);
	DrawTextureEx(m_pHostess->m_image, m_hostessPosition, 0, m_pHostess->m_textureScale, WHITE);
	showChoicesAndSetPlayerChoice();
}

void Situation::setClientAndHostess(Client* client, Hostess* hostess)
{
	Client* clientCopy = new Client(*client);
	m_pClient = clientCopy;
	m_pClient->m_hasHadSituation = true;


	Hostess* hostessCopy = new Hostess(*hostess);
	m_pHostess = hostessCopy;


}

void Situation::showChoicesAndSetPlayerChoice()
{
	Rectangle test{ 100, 200, 300, 430 };
	GuiGroupBox(test, "Choices");
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SIZE, 32);
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SPACING, 8);
	Vector2 startPosition{ 100, 100 };
	Rectangle smallGlassRec{ test.x, test.y + 30, 300, 60 };
	Rectangle bigGlassRec{ test.x, test.y + 130, 300, 60 };
	Rectangle towelRec{ test.x, test.y + 230, 300, 60 };
	Rectangle menuRec{ test.x, test.y + 330, 300, 60 };
	if (GuiButton(smallGlassRec, situationNames[1].c_str()))
	{
		m_playerChoice = SMALL_GLASS;
		answerChecker();
	}
	if (GuiButton(bigGlassRec, situationNames[2].c_str()))
	{
		m_playerChoice = BIG_GLASS;
		answerChecker();
	}
	if (GuiButton(towelRec, situationNames[3].c_str()))
	{
		m_playerChoice = TOWEL;
		answerChecker();
	}
	if (GuiButton(menuRec, situationNames[4].c_str()))
	{
		m_playerChoice = MENU;
		answerChecker();
	}


}

void Situation::answerChecker()
{
	if (m_playerChoice == m_sitType)
	{
		std::cout << "Player chose correctly!\n";
		m_isSituationOver = true;
	}
	else
	{
		std::cout << "Player has chosen incorrectly\n";
		m_isSituationOver = true;
	}
}

void Situation::assignSituationType()
{
	int random = GetRandomValue(1, 4);
	std::cout << random << std::endl;
	m_sitType = static_cast<SituationType>(random);
	situationName = situationNames[random];
}
