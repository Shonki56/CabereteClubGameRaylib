#pragma once
#include <raylib.h>

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
	enum Type type;
	Texture2D m_image;
	void Draw();
	void Update();
	Vector2 m_position;
	bool m_isBeingUsed;
	void changeToUsed();
};
