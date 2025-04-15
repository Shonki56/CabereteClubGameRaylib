#pragma once
#include "Client.hpp";
#include "Hostess.hpp";
#include "include/raygui.h"
class EndingSituation
{
public:
	enum playerChoice {DEFAULT, EXTEND_SESSION, GIVE_GIFT, GIRL_REWARD, PRAISE_GIRL};
	EndingSituation(Client* client, Hostess* hostess);
	Client* m_client;
	Hostess* m_hostess;
	void drawEndingSituation();

private:
	playerChoice m_playerChoice = DEFAULT;
	const std::string situationNames[5] = {"", "Extend Session?", "Give gift", "Give girl a reward", "Praise girl"};
	const Vector2 m_sofaPosition = { 400, 500 };
	const Vector2 m_clientPosition = { m_sofaPosition.x + 450, m_sofaPosition.y};
	const Vector2 m_hostessPosition = { m_sofaPosition.x + 150, m_sofaPosition.y - 50};
	const Texture2D m_sofaTexture = LoadTexture("resources/Images/sofa.png");
	void showChoices();
	void playerChoosesExtendSession();
	void playerChoosesGiveGift();
	void playerChoosesGiveGirlReward();
	void playerChoosesPraiseGirl();
};

