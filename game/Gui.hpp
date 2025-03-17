#pragma once
#include "Hostess.hpp"
#include "Client.hpp"
#include "raylib.h"
#include <string>
#include "include/raygui.h"
#include <iomanip>
#include "HostessManager.hpp"
#include "Situation.hpp"

namespace GUI
{
	void showHostessAndClientStats(const Hostess& hostess, const Client* client);
	void showComparison(const Hostess& hostess, Client* client);
	void showClientStats(const Client* client);
	void showMoneyEarnedByHostesses(Hostess hostesses[]);
	void showTimer(float timeRemaining);
	void showTitleScreen();
	void showEndScreen(HostessManager hostessManager);
}