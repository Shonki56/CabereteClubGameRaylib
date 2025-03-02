#include "Gui.hpp"



void GUI::showHostessAndClientStats(const Hostess& hostess, const Client* client)
{
	Rectangle statsRec = { 50, 800, 300, 250 };
	int xOffSetStats = 10;
	int xOffsetTraits = 170;
	DrawRectangleRec(statsRec, WHITE);
	DrawLineEx({ 190, 800 }, { 190, 1100 }, 8.0f, BLACK);

	int startY = 20;
	for (int i = 0; i < 4; i++)
	{
		std::string statsText = hostess.statNames[i] + ": " + std::to_string(hostess.m_stats[i]);
		if (client->selectedStat == i)
			DrawText(statsText.c_str(), statsRec.x + xOffSetStats, statsRec.y + startY, 20, GREEN);
		else
			DrawText(statsText.c_str(), statsRec.x + xOffSetStats, statsRec.y + startY, 20, DARKGRAY);


		std::string traitsText = hostess.traitNames[i] + ": " + std::to_string(hostess.m_traits[i]);
		if (client->selectedTrait == i)
			DrawText(traitsText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + startY, 20, GREEN);
		else
			DrawText(traitsText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + startY, 20, DARKGRAY);


		startY += 20;

	}

	showClientStats(client);
}

void GUI::showComparison(const Hostess& hostess, Client* client)
{
	int selectedTraitClient = client->m_traits[client->selectedTrait];
	int selectedStatClient = client->m_stats[client->selectedStat];
	int selectedTraitHostess = hostess.m_traits[client->selectedTrait];
	int selectedStatHostess = hostess.m_stats[client->selectedStat];

	Vector2 recPosition = { 380, 850 };
	Vector2 recSize = { 100, 100 };
	
	
	if (selectedTraitHostess > selectedTraitClient && selectedStatHostess > selectedStatClient)
	{
		DrawRectangleV(recPosition, recSize, GREEN);
		client->m_happiness = HIGH;
	}
	else if (selectedTraitHostess >= selectedTraitClient || selectedStatHostess >= selectedStatClient)
	{
		DrawRectangleV(recPosition, recSize, YELLOW);
		client->m_happiness = MEDIUM;
	}
	else
	{
		DrawRectangleV(recPosition, recSize, RED);
		client->m_happiness = LOW;
	}


}

void GUI::showClientStats(const Client* client)
{
	Rectangle statsRec = { 500, 800, 300, 250 };
	float lineXPosition = (statsRec.x + statsRec.width) - (statsRec.width / 2);
	int xOffSetStats = 10;
	int xOffsetTraits = 170;
	DrawRectangleRec(statsRec, WHITE);
	DrawLineEx({ lineXPosition, 800 }, { lineXPosition, 1100 }, 8.0f, BLACK);
	int startX = 20;

	for (int i = 0; i < 4; i++)
	{
		std::string statsText = client->statNames[i] + ": " + std::to_string(client->m_stats[i]);
		if (i == client->selectedStat)
		{
			DrawText(statsText.c_str(), statsRec.x + xOffSetStats, statsRec.y + startX, 20, GREEN);
		}
		else
			DrawText(statsText.c_str(), statsRec.x + xOffSetStats, statsRec.y + startX, 20, DARKGRAY);


		std::string traitsText = client->traitNames[i] + ": " + std::to_string(client->m_traits[i]);
		if (i == client->selectedTrait)
			DrawText(traitsText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + startX, 20, GREEN);
		else
			DrawText(traitsText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + startX, 20, DARKGRAY);

		startX += 30;
	}

}
