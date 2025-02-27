#pragma once
#include "Hostess.hpp"
#include "Client.hpp"
#include "raylib.h"
#include <string>
#include "include/raygui.h"

namespace GUI
{
	void showHostessStats(const Hostess& hostess);
	void showComparison(const Hostess& hostess, const Client* client);
	void showClientStats(const Client* client);

}