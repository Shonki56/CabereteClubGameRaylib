#pragma once
#include <raylib.h>

class Sofa
{
public:
	Sofa(Vector2 position);
	~Sofa();
	bool m_isBeingUsed;
	void Draw();
	void Update();
	Vector2 m_position;
	Texture m_image;
	Rectangle getRect();
	Rectangle m_area;
private:
	bool isMouseOnSofa();
	void ChangeToActive();
	float m_sofaSize = 0.35;
	void isSofaBeingUsed();
};
