#pragma once
#include "Sofa.h"
#include "Client.hpp"
#include "Hostess.hpp"


namespace GameLogic
{
	void clientSpendMoney(Hostess* hostess, const Client* client);
	void howOftenToGiveMoney(Client* client);
	void playSituation(Hostess* hostess, Client* client);
}
