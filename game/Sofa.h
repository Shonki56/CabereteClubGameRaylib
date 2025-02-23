#pragma once
#include <raylib.h>
#include "Hostess.hpp";
#include "Client.hpp";

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
	void ChangeToActive();
	Hostess* m_currentHostess;
	Client* m_currentClient;
private:
	float m_sofaSize = 0.35;
	void isSofaBeingUsed();
};
