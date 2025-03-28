#include "Sofa.h"
#include <iostream>

Sofa::Sofa(Vector2 position)
{
	m_isBeingUsed = false;
	m_image = LoadTexture("resources/Images/sofa.png");
	this->m_position = position;
	m_area = getRect();
	m_currentClient = nullptr;
	m_currentSituation = nullptr;
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

	if (m_currentSituation != nullptr && m_currentClient != nullptr && m_currentClient->m_hasHadSituation == false && m_isBeingUsedByClientAndHostess == true)
	{
		DrawText("!", m_position.x, m_position.y - 100, 100, RED);
	}

	if (m_currentSituation == nullptr && m_currentClient != nullptr && m_currentHostess != nullptr)
	{
		createSituation();
	}
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

void Sofa::createSituation()
{
	if (m_currentClient->m_hasSituationReady == true && m_currentClient->m_hasHadSituation == false)
	{
		m_currentSituation = new Situation(m_currentHostess, m_currentClient);
		std::cout << "Situation Created!" << std::endl;
	}
}

bool Sofa::checkIfPressedToStartSituation()
{
	if (CheckCollisionPointRec(GetMousePosition(), m_area) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && m_currentSituation != nullptr)
	{
		m_currentClient->m_hasHadSituation = true;
		std::cout << "Situation pressed on\t";
		return true;
	}
}

void Sofa::isSofaBeingUsed()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		Vector2 mousePosition = GetMousePosition();
		if (CheckCollisionPointRec(mousePosition, m_area))
		{
			if (!m_isBeingUsed)
			{
				ChangeToActive();
				std::cout << "Now True!\n";
			}
			else
			{
				m_isBeingUsed = false;
				m_currentSituation = nullptr; // hasn't worked
				std::cout << "Now False!\n";
			}
		}
	}
}

