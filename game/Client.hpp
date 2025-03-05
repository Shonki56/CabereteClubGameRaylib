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
	clientType m_type;
	clientHappiness m_happiness;
	void getCorrectType();
	Vector2 m_position;
	bool m_isSeated;
	float m_timeout;
	float m_timeSpawnedIn;
	float m_timeSinceLastSpentMoney;
	float m_howOftenToSpendMoney;
	StatsAndTraits m_statsAndTraits;
	int selectedTrait = GetRandomValue(0, 3);
	int selectedStat = GetRandomValue(0, 3);
private:
	void createStatsAndTraits();
	void InitClient();

};
