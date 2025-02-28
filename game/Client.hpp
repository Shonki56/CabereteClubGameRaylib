#pragma once
#include <raylib.h>
#include "Hostess.hpp"
#include <map>
#include<string>
#include "StatsAndTraits.h"

enum clientHappiness{ NOT, LITTLE, MEDIUM, MUCH, VERYMUCH }; 
enum clientType{POOR, AVERAGE, RICH, MEGARICH};
class Client
{
public:
	Client(clientType clientType);
	~Client();
	Texture2D m_clientImage;
	void Draw();
	void Update();
	clientHappiness howMuchDoesClientLikeHostess(Hostess& hostess);
	clientType m_type;
	void getCorrectType();
	Vector2 m_position;
	bool m_isSeated;
	float m_timeout;
	float m_timeSpawnedIn;
	stuff::Stats m_statsStruct;
	stuff::Traits m_traitsStruct;
	std::map<std::string, int> statsMap;
	std::vector<int> m_stats;
	std::vector<int> m_traits;
	std::vector<std::string> statNames = { "Talk", "Love", "Party", "Skill" };
	std::vector<std::string> traitNames = { "Sexy", "Beauty", "Cute", "Funny" };
	int selectedTrait = GetRandomValue(0, 3);
	int selectedStat = GetRandomValue(0, 3);
private:
	void createStatsAndTraits();
	void InitClient();
	void printStats();

};
