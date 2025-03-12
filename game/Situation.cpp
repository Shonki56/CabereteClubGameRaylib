#include "Situation.hpp"

void Situation::DrawSituation()
{
	m_sofa.m_sofaSize = 1.0f;
	m_sofa.m_position = { (static_cast<float>(GetScreenWidth()) - m_sofa.m_image.width) / 2, 500};
	m_client->m_size = 10.0f;
	m_client->m_position = { m_sofa.m_position.x + 300, 500 };
	m_hostess->m_position = { m_sofa.m_position.x, 450 };
	m_hostess->m_size = 1.5f;
	
	m_sofa.Draw();
	m_client->DrawAndUpdate();
	m_hostess->Draw();
}
