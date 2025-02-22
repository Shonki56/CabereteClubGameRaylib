#include "Hostess.hpp"

Hostess::Hostess()
{
	m_isBeingUsed = false;
	m_isCurrentlySelected = false;
}

void Hostess::Draw()
{
	if (m_isBeingUsed)
	{
		DrawTextureEx(m_image, m_position, 0, 0.6, WHITE);
	}

}

Rectangle Hostess::getRect()
{
	Rectangle rect;
	rect.x = m_faceImagePosition.x;
	rect.y = m_faceImagePosition.y;
	rect.width = m_faceImage.width;
	rect.height = m_faceImage.height;
	return rect;
}
