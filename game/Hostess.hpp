#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <StatsAndTraits.h>

class Hostess
{
public:
	Hostess();
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
	StatsAndTraits m_statsAndTraits;
	int m_moneyMade;

};
