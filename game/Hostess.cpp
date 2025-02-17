#include "Hostess.hpp"

Hostess::Hostess()
{
	m_isBeingUsed = false;
}

void Hostess::Draw()
{
	if (m_isBeingUsed)
	{
		DrawTextureEx(m_image, m_position, 0, 0.6, WHITE);
	}

}

void Hostess::changeToUsed()
{
	m_isBeingUsed = true;
}
