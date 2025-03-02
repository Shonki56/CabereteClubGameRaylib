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

void Client::Draw()
{
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, WHITE);
}

void Client::getCorrectType()
{
	// Placeholder for now;
	if (m_type == POOR)
	{
		m_clientImage = LoadTexture("resources/Images/client_poor.png");
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
	default:
		std::cout << "Something has went wrong!\n";
	}


	for (int i = 0; i < 4; i++)
	{
		m_stats.push_back(GetRandomValue(minStat, maxStat));
		m_traits.push_back(GetRandomValue(minStat, maxStat));
	}
}

void Client::InitClient()
{
	getCorrectType();
	createStatsAndTraits();
	m_position = { 298, 67 };
	m_isSeated = false;
	m_timeout = 10.0f;
	m_timeSpawnedIn = GetTime();
}

