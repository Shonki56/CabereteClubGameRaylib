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
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, WHITE);
	m_clientTimer.updateCurrentTimeAndTimeLeft();
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
	m_clientTimer.setTotalTime(7.0f);
	m_clientTimer.startTimer();
}

