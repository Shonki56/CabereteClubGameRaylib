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

	statsMap = {
		{"Talk", GetRandomValue(1, 30)},
		{"Love", GetRandomValue(1, 30)},
		{"Party", GetRandomValue(1, 30)},
		{"Skill", GetRandomValue(1, 30)},
	};


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

