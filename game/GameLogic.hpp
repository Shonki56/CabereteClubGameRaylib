#pragma once
#include "Sofa.h"
#include "Client.hpp"
#include "Hostess.hpp"


namespace GameLogic
{
	void clientSpendMoney(Hostess* hostess, const Client* client);
	void howOftenToGiveMoney(Client* client);
}
