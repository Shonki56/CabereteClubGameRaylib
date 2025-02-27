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
	// USING VECTORS INSTEAD

	for (int i = 0; i < 4; i++)
	{
		m_stats.push_back(GetRandomValue(1, 30));
		m_traits.push_back(GetRandomValue(1, 30));
	}



	// Using only one stat and trait for now
	int randomNumberForTraits = GetRandomValue(0, 3);
	int randomNumberForStats = GetRandomValue(0, 3);
	int randomNumberForActualTraitPoor = GetRandomValue(1, 30);
	int randomNumberForActualStatPoor = GetRandomValue(1, 30);
	switch (randomNumberForTraits)
	{
	case 0:
		m_traitsStruct.m_Sexy = GetRandomValue(1, 30);
		break;
	case 1:
		m_traitsStruct.m_Beauty = GetRandomValue(1, 30);
		break;
	case 2:
		m_traitsStruct.m_Cute = GetRandomValue(1, 30);
		break;
	case 3:
		m_traitsStruct.m_Funny = GetRandomValue(1, 30);
		break;
	}


	switch (randomNumberForStats)
	{
	case 0:
		m_statsStruct.m_Talk = GetRandomValue(1, 30);
		break;
	case 1:
		m_statsStruct.m_Love = GetRandomValue(1, 30);
		break;
	case 2:
		m_statsStruct.m_Party = GetRandomValue(1, 30);
		break;
	case 3:
		m_statsStruct.m_Skill = GetRandomValue(1, 30);
		break;
	default:
		std::cout << "Random number for Stats is: " << randomNumberForStats << std::endl;
	}
}

void Client::InitClient()
{
	m_traitsStruct = { 0, 0, 0, 0 };
	m_statsStruct = {0, 0, 0, 0, 0 };
	createStatsAndTraits();
	getCorrectType();
	m_position = { 298, 67 };
	m_isSeated = false;
	m_timeout = 10.0f;
	m_timeSpawnedIn = GetTime();
	printStats();
}

void Client::printStats()
{
	std::cout << "STATS\n";
	std::cout << "Client Talk Stat: " << m_statsStruct.m_Talk << std::endl;
	std::cout << "Client Love Stat: " << m_statsStruct.m_Love << std::endl;
	std::cout << "Client Party Stat: " << m_statsStruct.m_Party << std::endl;
	std::cout << "Client Skill Stat: " << m_statsStruct.m_Skill << std::endl;


	std::cout << "TRAITS\n";
	std::cout << "Client Sexy Trait: " << m_traitsStruct.m_Sexy << std::endl;
	std::cout << "Client Beauty Trait: " << m_traitsStruct.m_Beauty << std::endl;
	std::cout << "Client Cute Trait: " << m_traitsStruct.m_Cute << std::endl;
	std::cout << "Client Funny Trait: " << m_traitsStruct.m_Funny << std::endl;
}

