#include "GameLogic.hpp"

// Depending on how happy the client are the spend money more quickly but the amount is the same

enum questionType {TOWEL, MENU, SHOT_GLASS
};

void GameLogic::clientSpendMoney(Hostess* hostess, const Client* client)
{
	switch (client->m_type)
	{
	case POOR:
		hostess->m_moneyMade += GetRandomValue(10, 100);
		break;
	case AVERAGE:
		hostess->m_moneyMade += GetRandomValue(100, 800);
		break;
	case RICH:
		hostess->m_moneyMade += GetRandomValue(1000, 3000);
		break;
	case MEGARICH:
		hostess->m_moneyMade += GetRandomValue(10, 100);
		break;
	}

}

void GameLogic::howOftenToGiveMoney(Client* client)
{
	switch (client->m_happiness)
	{
	case LOW:
		client->m_howOftenToSpendMoney = 10.0f;
		break;
	case MEDIUM:
		client->m_howOftenToSpendMoney = 6.0f;
		break;
	case HIGH:
		client->m_howOftenToSpendMoney = 4.0f;
		break;
	case SPECIAL:
		client->m_howOftenToSpendMoney = 2.0f;
		break;
	}
}

void GameLogic::playSituation(Hostess* hostess, Client* client)
{
	
}
