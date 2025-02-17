#include "Sofa.h"
#include <iostream>

Sofa::Sofa(Vector2 position)
{
	m_isBeingUsed = false;
	m_image = LoadTexture("resources/Images/sofa.png");
	this->m_position = position;
	m_area = getRect();
}

Sofa::~Sofa()
{
	//UnloadTexture(m_image);
}

void Sofa::Draw()
{
	DrawTextureEx(m_image, m_position,0, m_sofaSize, WHITE);	
	if (m_isBeingUsed)
	{
		DrawRectangleLinesEx(m_area, 2.0, RED);
	}
	else
	{
		DrawRectangleLinesEx(m_area, 2.0, WHITE);
	}
}

void Sofa::Update()
{
	isSofaBeingUsed();
}

Rectangle Sofa::getRect()
{
	Rectangle rect;
	rect.x = m_position.x;
	rect.y = m_position.y;
	rect.width = m_image.width * m_sofaSize;
	rect.height = m_image.height * m_sofaSize;
	return rect;
}

void Sofa::ChangeToActive()
{
	m_isBeingUsed = true;
	std::cout << "Changed to active!\n";
}

void Sofa::isSofaBeingUsed()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isMouseOnSofa())
	{
		if (!m_isBeingUsed)
		{
			m_isBeingUsed = true;
			std::cout << "Now true!\n";
		}
		else
		{
			m_isBeingUsed = false;
			std::cout << "Now false!\n";
		}

	}

}

bool Sofa::isMouseOnSofa()
{
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();

	if (mouseX >= m_area.x && mouseX <= m_area.x + m_area.width &&
		mouseY >= m_area.y && mouseY <= m_area.y + m_area.height)
	{
		return true;
	}
	return false;
}

