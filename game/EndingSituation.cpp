#include "EndingSituation.h"

EndingSituation::EndingSituation(Client* client, Hostess* hostess) : m_client(client), m_hostess(hostess) {}

void EndingSituation::drawEndingSituation()
{
	DrawTexture(m_sofaTexture, 500, 500, WHITE);
	DrawTextureEx(m_client->m_clientImage, m_clientPosition, 0, m_client->m_textureScale, WHITE);
	DrawTextureEx(m_hostess->m_image, m_hostessPosition, 0, m_hostess->m_textureScale, WHITE);
	showChoices();
}

void EndingSituation::playerChoosesExtendSession()
{
	std::cout << "Player chose to extend session\n";
}

void EndingSituation::playerChoosesGiveGift()
{
	std::cout << "Player chose to give client a gift\n";
}

void EndingSituation::playerChoosesGiveGirlReward()
{
	std::cout << "Player chose to give girl a reward\n";
}

void EndingSituation::playerChoosesPraiseGirl()
{
	std::cout << "Player chose to praise girl\n";
}

void EndingSituation::showChoices()
{
	const Rectangle outerBoxThatContainsButtons{ 100, 200, 300, 430 };
	GuiGroupBox(outerBoxThatContainsButtons, "Choices");
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SIZE, 32);
	GuiSetStyle(DEFAULT, GuiDefaultProperty::TEXT_SPACING, 2);
	const Vector2 startPosition{ 100, 100 };
	const Rectangle choiceOne{ outerBoxThatContainsButtons.x, outerBoxThatContainsButtons.y + 30, 300, 60 };
	const Rectangle choiceTwo{ outerBoxThatContainsButtons.x, outerBoxThatContainsButtons.y + 130, 300, 60 };
	const Rectangle choiceThree{ outerBoxThatContainsButtons.x, outerBoxThatContainsButtons.y + 230, 300, 60 };
	const Rectangle choiceFour{ outerBoxThatContainsButtons.x, outerBoxThatContainsButtons.y + 330, 300, 60 };
	if (GuiButton(choiceOne, situationNames[1].c_str()))
	{
		m_playerChoice = EXTEND_SESSION;
		playerChoosesExtendSession();
	}
	if (GuiButton(choiceTwo, situationNames[2].c_str()))
	{
		m_playerChoice = GIVE_GIFT;
		playerChoosesGiveGift();
	}
	if (GuiButton(choiceThree, situationNames[3].c_str()))
	{
		m_playerChoice = GIRL_REWARD;
		playerChoosesGiveGirlReward();
	}
	if (GuiButton(choiceFour, situationNames[4].c_str()))
	{
		m_playerChoice = PRAISE_GIRL;
		playerChoosesPraiseGirl();
	}
}
