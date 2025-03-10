#include "Client.hpp"
#include <iostream>

Client::Client(clientType clientType) : m_type(clientType)
{
	InitClient();
}

Client::~Client()
{
	//if (m_type == POOR)
	//	UnloadTexture(m_clientImage);
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
	//DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, WHITE);
	m_lifetime.updateCurrentTimeAndTimeLeft();
	m_spendMoneyTimer.updateCurrentTimeAndTimeLeft();
	//if (m_spendMoneyTimer.m_hasTimerRunOut)
	//{
	//	m_spendMoneyTimer.resetTimer();
	//	std::cout << "Timer has been reset\n";
	//	m_timeToPay = true;
	//}
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
	//m_position = { 298, 67 };
	m_isSeated = false;
	m_lifetime.setTotalTime(20.0f);
	m_lifetime.startTimer();
	m_spendMoneyTimer.setTotalTime(3.0f); // this needs moving so it starts when a hostess is placed on a sofa with a client
	m_spendMoneyTimer.startTimer();
}

