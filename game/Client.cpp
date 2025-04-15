#include "Client.hpp"
#include <iostream>

Client::Client(clientType clientType) : m_type(clientType)
{
	InitClient();
}

Client::~Client()
{
	UnloadTexture(m_clientImage);
}

void Client::DrawAndUpdate()
{
	switch (m_type)
	{
	case POOR:
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, WHITE);
	break;
	case AVERAGE:
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, BLUE);
	break;
	case RICH:
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, RED);
	break;
	case MEGARICH:
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, PURPLE);
	break;
	default:
		std::cout << "Something went wrong loading client texture!\n";
	}
	m_lifetimeTimer.updateCurrentTimeAndTimeLeft();
	m_spendMoneyTimer.updateCurrentTimeAndTimeLeft();
	//std::cout << m_spendMoneyTimer.getTimeLeft() << std::endl; // for some reason it resets back to old value

}

void Client::getCorrectType()
{
	switch (m_type)
	{
	case POOR:
	m_clientImage = LoadTexture("resources/Images/client_poor.png");
	break;
	case AVERAGE:
	m_clientImage = LoadTexture("resources/Images/client_poor.png");
	break;
	case RICH:
	m_clientImage = LoadTexture("resources/Images/client_poor.png");
	break;
	case MEGARICH:
	m_clientImage = LoadTexture("resources/Images/client_poor.png");
	break;
	default:
		std::cout << "Something went wrong loading client texture!\n";
	}

}

float Client::m_howMuchToSpend()
{
	switch (m_type)
	{
	case POOR:
		return GetRandomValue(10, 100);
		break;
	case AVERAGE:
		return GetRandomValue(100, 800);
		break;
	case RICH:
		return GetRandomValue(1000, 3000);
		break;
	case MEGARICH:
		return GetRandomValue(3000, 10000);
		break;
	}
}

void Client::setTimers()
{
	m_spendMoneyTimer.setTotalTime(getClientHappinessHowOftenToSpendMoney());
	m_lifetimeTimer.setTotalTime(15);
	m_spendMoneyTimer.startTimer();
	m_lifetimeTimer.startTimer();
}

void Client::pauseTimers()
{
	m_lifetimeTimer.pauseTimer();
	m_spendMoneyTimer.pauseTimer();
}

void Client::continueTimers()
{
	m_lifetimeTimer.continueTimer();
	m_spendMoneyTimer.continueTimerWithoutAddingPausedTime(); // No longer adding paused time, but now it isnt using the correct time
}

void Client::setHowOftenToSpendMoney()
{
	float time = getClientHappinessHowOftenToSpendMoney();
	std::cout << time << std::endl;
	m_spendMoneyTimer.setTotalTime(time);
}

void Client::setHappiness(clientHappiness happiness)
{
	m_happiness = happiness;
	setHowOftenToSpendMoney();
	m_spendMoneyTimer.resetTimer();
}

float Client::getClientHappinessHowOftenToSpendMoney()
{
	switch (m_happiness)
	{
	case LOW:
		return 10.0f;
		break;
	case MEDIUM:
		return 6.0f;
		break;
	case HIGH:
		return 2.5f;
		break;
	case SPECIAL:
		return 1.8f;
		break;
	}
}

void Client::createStatsAndTraits()
{
	int minStat = 0;
	int maxStat = 0;
	switch (m_type)
	{
	case POOR:
		minStat = 1;
		maxStat = 20;
		break;
	case AVERAGE:
		minStat = 10;
		maxStat = 30;
		break;
	case RICH:
		minStat = 20;
		maxStat = 60;
		break;
	case MEGARICH:
		minStat = 40;
		maxStat = 80;
		break;
	default:
		std::cout << "Something has went wrong getting client stats\n";
	}


	for (int i = 0; i < 4; i++)
	{
		m_statsAndTraits.m_stats.push_back(GetRandomValue(minStat, maxStat));
		m_statsAndTraits.m_traits.push_back(GetRandomValue(minStat, maxStat));
	}
}

void Client::InitClient()
{
	getCorrectType();
	createStatsAndTraits();
	m_isSeated = false;
}

