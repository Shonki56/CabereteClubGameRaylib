#include "Situation.hpp"

Situation::Situation()
{
	assignSituationType();
	setHostessNeedTexture();
}

Situation::Situation(Client* client, Hostess* hostess)
{
	m_pClient = client;
	m_pHostess = hostess;
	assignSituationType();
	setHostessNeedTexture();
}

Situation::~Situation()
{
	UnloadTexture(m_hostessNeddTexture);
	UnloadTexture(m_sofaTexture);
	TraceLog(LOG_DEBUG, "SITUATION DELETED");
}

void Situation::Draw()
{
	DrawTexture(m_sofaTexture, 500, 500, WHITE);
	DrawTextureEx(m_pClient->m_clientImage, m_clientPosition, 0, m_pClient->m_textureScale, WHITE);
	DrawTextureEx(m_pHostess->m_image, m_hostessPosition, 0, m_pHostess->m_textureScale, WHITE);
	showChoicesAndSetPlayerChoice();

	switch (m_sitType)
	{
	case TOWEL:
		DrawTextureEx(m_hostessNeddTexture, { 800, 300 }, 0, 0.25, WHITE);
		break;
	case BIG_GLASS:
		DrawTextureEx(m_hostessNeddTexture, { 800, 300 }, 0, 0.25, WHITE);
		break;
	case SMALL_GLASS:
		DrawTextureEx(m_hostessNeddTexture, { 800, 350 }, 0, 0.5, WHITE);
		break;
	case MENU:
		DrawTextureEx(m_hostessNeddTexture, { 800, 350 }, 0, 0.5, WHITE);
		break;
	}
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
		if (m_pClient->m_happiness != clientHappiness::HIGH)
		{
			int currentClientHappiness = static_cast<int>(m_pClient->m_happiness);
			int improveClientHappiness = currentClientHappiness + 1;
			m_pClient->m_happiness = static_cast<clientHappiness>(improveClientHappiness);
			m_pClient->setHowOftenToSpendMoney();
			m_pClient->m_spendMoneyTimer.resetTimer();
		}
		m_isSituationOver = true;
	}
	else
	{
		std::cout << "Player has chosen incorrectly\n";
		m_isSituationOver = true;
	}
}

void Situation::setHostessNeedTexture()
{
	switch (m_sitType)
	{
	case SMALL_GLASS:
		m_hostessNeddTexture = LoadTexture("resources/Images/Situations/small_glass.png");
		break;
	case BIG_GLASS:
		m_hostessNeddTexture = LoadTexture("resources/Images/Situations/large_glass.png");
		break;
	case MENU:
		m_hostessNeddTexture = LoadTexture("resources/Images/Situations/menu.jpg");
		break;
	case TOWEL:
		m_hostessNeddTexture = LoadTexture("resources/Images/Situations/towel.png");
		break;
	}
}

void Situation::improveHappiness()
{
	m_pClient->m_happiness = HIGH;
}

void Situation::assignSituationType()
{
	int random = GetRandomValue(1, 4);
	std::cout << random << std::endl;
	m_sitType = static_cast<SituationType>(random);
	situationName = situationNames[random];
}
