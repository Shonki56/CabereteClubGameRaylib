#include "Client.hpp"
#include <iostream>

Client::Client(clientType clientType) : m_type(clientType)
{
	getCorrectType();
	m_position = { 298, 67 };
	m_isSeated = false;
	m_timeout = 10.0f;
	m_timeSpawnedIn = GetTime();
}

Client::~Client()
{
	//if (m_type == POOR)
	//	UnloadTexture(m_clientImage);
}

void Client::Draw()
{
	DrawTextureEx(m_clientImage, {m_position.x, m_position.y}, 0.0f, 3.0f, WHITE);
}

void Client::getCorrectType()
{
	// Placeholder for now;
	if (m_type == POOR)
	{
		m_clientImage = LoadTexture("resources/Images/client_poor.png");
	}

}
