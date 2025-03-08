#pragma once
#include <raylib.h>
#include "Hostess.hpp"
#include <map>
#include<string>
#include "StatsAndTraits.h"
#include "Timer.hpp"
enum clientHappiness{ LOW, MEDIUM, HIGH, SPECIAL }; 
enum clientType{POOR, AVERAGE, RICH, MEGARICH};

class Client
{
public:
	Client(clientType clientType);
	~Client();
	Texture2D m_clientImage;
	void DrawAndUpdate();
	clientType m_type;
	clientHappiness m_happiness;
	void getCorrectType();
	Vector2 m_position;
	bool m_isSeated;
	StatsAndTraits m_statsAndTraits;
	int selectedTrait = GetRandomValue(0, 3);
	int selectedStat = GetRandomValue(0, 3);
	Timer m_lifetime;
	Timer m_spendMoneyTimer;
	float m_howMuchToSpend();
	bool m_timeToPay = false;
private:
	void createStatsAndTraits();
	void InitClient();

};
