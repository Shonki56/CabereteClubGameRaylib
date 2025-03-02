#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>

struct Stats
{
	int m_healthPoints;
	int m_Talk;
	int m_Love;
	int m_Party;
	int m_Skill;
};

struct Traits
{
	int m_Sexy;
	int m_Beauty;
	int m_Cute;
	int m_Funny;
};

class Hostess
{
public:
	Hostess();
	Stats stats;
	Traits traits;
	Texture2D m_image;
	void Draw();
	Vector2 m_position;
	bool m_isBeingUsed;
	Texture2D m_faceImage;
	bool m_isCurrentlySelected;
	Rectangle m_faceImageRectangle;
	Vector2 m_faceImagePosition;
	Rectangle getRect();
	int m_sofaCurrentlyOn;
	std::string m_name;
	std::vector<int> m_traits;
	std::vector<int> m_stats;
	std::vector<std::string> statNames = { "Talk", "Love", "Party", "Skill" };
	std::vector<std::string> traitNames = { "Sexy", "Beauty", "Cute", "Funny" };
	int m_moneyMade;
};
