#include "Client.hpp"
#include <iostream>

Client::Client(clientType clientType) : m_type(clientType)
{
	getCorrectType();
}

Client::~Client()
{
	if (m_type == POOR)
		UnloadTexture(m_clientImage);
}

void Client::Draw()
{
	DrawTextureEx(m_clientImage, {100, 100}, 0.0f, 3.0f, WHITE);
}

void Client::getCorrectType()
{
	// Placeholder for now;
	if (m_type == POOR)
	{
		m_clientImage = LoadTexture("resources/Images/client_poor.png");
	}

}
