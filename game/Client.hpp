#pragma once
#include <raylib.h>
#include "Hostess.hpp"
#include <map>
#include<string>
#include "StatsAndTraits.h"
enum clientHappiness{ LOW, MEDIUM, HIGH, SPECIAL }; 
enum clientType{POOR, AVERAGE, RICH, MEGARICH};

class Client
{
public:
	Client(clientType clientType);
	~Client();
	Texture2D m_clientImage;
	void Draw();
	void Update();
	clientType m_type;
	clientHappiness m_happiness;
	void getCorrectType();
	Vector2 m_position;
	bool m_isSeated;
	float m_timeout;
	float m_timeSpawnedIn;
	std::vector<int> m_stats;
	std::vector<int> m_traits;
	std::vector<std::string> statNames = { "Talk", "Love", "Party", "Skill" };
	std::vector<std::string> traitNames = { "Sexy", "Beauty", "Cute", "Funny" };
	int selectedTrait = GetRandomValue(0, 3);
	int selectedStat = GetRandomValue(0, 3);
	int m_moneyToSpend;
private:
	void createStatsAndTraits();
	void InitClient();
	void printStats();

};
