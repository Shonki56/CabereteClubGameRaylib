#pragma once
#include "Hostess.hpp"
#include "Client.hpp"
#include "raylib.h"
#include <string>
#include "include/raygui.h"

namespace GUI
{
	void showHostessAndClientStats(const Hostess& hostess, const Client* client);
	void showComparison(const Hostess& hostess, const Client* client);
	void showClientStats(const Client* client);

}