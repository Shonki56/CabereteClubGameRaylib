#include "Gui.hpp"



void GUI::showHostessStats(const Hostess& hostess)
{
	Rectangle statsRec = { 50, 800, 300, 250 };
	int xOffSetStats = 10;
	int xOffsetTraits = 170;
	DrawRectangleRec(statsRec, WHITE);
	DrawLineEx({ 190, 800 }, { 190, 1100 }, 8.0f, BLACK);

	// TODO Change this to be the same as showClientStats

	// Stats
	std::string healthText = "HP: " + std::to_string(hostess.stats.m_healthPoints);
	std::string talkText = "Talk: " + std::to_string(hostess.stats.m_Talk);
	std::string loveText = "Love: " + std::to_string(hostess.stats.m_Love);
	std::string partyText = "Party: " + std::to_string(hostess.stats.m_Party);
	std::string skillText = "Skill: " + std::to_string(hostess.stats.m_Skill);
	DrawText(healthText.c_str(), statsRec.x + xOffSetStats, statsRec.y + 20, 20, DARKGRAY);
	DrawText(talkText.c_str(), statsRec.x + xOffSetStats, statsRec.y + 50, 20, DARKGRAY);
	DrawText(loveText.c_str(), statsRec.x + xOffSetStats, statsRec.y + 80, 20, DARKGRAY);
	DrawText(partyText.c_str(), statsRec.x + xOffSetStats, statsRec.y + 110, 20, DARKGRAY);
	DrawText(skillText.c_str(), statsRec.x + xOffSetStats, statsRec.y + 140, 20, DARKGRAY);

	// Traits

	std::string sexyText = "Sexy: " + std::to_string(hostess.traits.m_Sexy);
	std::string beautyText = "Beauty: " + std::to_string(hostess.traits.m_Beauty);
	std::string cuteText = "Cute: " + std::to_string(hostess.traits.m_Cute);
	std::string funnyText = "Funny: " + std::to_string(hostess.traits.m_Funny);

	DrawText(sexyText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + 20, 20, DARKGRAY);
	DrawText(beautyText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + 50, 20, DARKGRAY);
	DrawText(cuteText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + 80, 20, DARKGRAY);
	DrawText(funnyText.c_str(), statsRec.x + xOffsetTraits, statsRec.y + 110, 20, DARKGRAY);


}

void GUI::showComparison(const Hostess& hostess, const Client* client)
{
	int selectedTrait;
	int selectedStat;


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

	int testInt = 20;


	// USING MAP 
	for (const auto& stat : client->statsMap)
	{
		std::string text = stat.first + ": " + std::to_string(stat.second);
		if (client->statNames[client->selectedStat] == stat.first)
			DrawText(text.c_str(), 300, testInt, 20, GREEN);
		else
			DrawText(text.c_str(), 300, testInt, 20, WHITE);
		testInt += 30;
	}

	// USING VECTOR

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
