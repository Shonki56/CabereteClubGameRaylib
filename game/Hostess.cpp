#include "Hostess.hpp"

Hostess::Hostess()
{
	m_isBeingUsed = false;
}

void Hostess::Draw()
{
	DrawTextureEx(m_image, m_position, 0, 1, WHITE);
}

void Hostess::changeToUsed()
{
	m_isBeingUsed = true;
}
