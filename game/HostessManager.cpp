#include "HostessManager.hpp"

HostessManager::HostessManager()
{
	initHostesses();
}

void HostessManager::placeHostess(Hostess& hostess, Sofa& sofa)
{

	if (!sofa.m_isBeingUsed && hostess.m_isCurrentlySelected && hostess.m_isBeingUsed == false && sofa.m_currentClient != nullptr)
	{
		hostess.m_position = sofa.m_position;
		hostess.m_position.y -= 50;
		hostess.m_isBeingUsed = true;
		hostess.m_isCurrentlySelected = false;
		sofa.m_isBeingUsed = true;
		sofa.m_currentHostess = &hostess;


	}
	else if (sofa.m_isBeingUsed == true) 
	{
		std::cout << "Sofa is being used!\n";
	}
	else if (hostess.m_isCurrentlySelected == false)
	{
		std::cout << "Hostess not currently selected!\n";
	}
	else if (hostess.m_isBeingUsed == true)
	{
		std::cout << "Hostess being used!\n";
	}
	else if (sofa.m_currentClient == nullptr)
	{
		std::cout << "Client not on sofa\n";
	}
	else
	{
		std::cout << "Adding incomplete\n";
	}


}

void HostessManager::removeHostess(Hostess& hostess, Sofa& sofa)
{
	if (sofa.m_isBeingUsed && sofa.m_currentHostess == &hostess)
	{
		sofa.m_isBeingUsed = false;
		hostess.m_isBeingUsed = false;
		sofa.m_currentHostess = nullptr;

	}
	else
	{
		std::cout << "Removal not needed!\n";
	}
}

void HostessManager::unselectAllHostesses()
{
	for (auto& hostess : m_hostesses)
	{
		hostess.m_isCurrentlySelected = false;
	}
}

bool HostessManager::isAHostessCurrentlySelected()
{

	for (auto& hostess : m_hostesses)
	{
		if (hostess.m_isCurrentlySelected == true)
		{
			m_selectedHostess = hostess;
			return true;

		}
	}

	return false;

}

void HostessManager::initHostesses()
{
	m_hostesses[0].m_image = LoadTexture("resources/Images/fullBodyGirls/Angelica.png");
	m_hostesses[0].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Angelica-Head.png");
	m_hostesses[0].m_name = "Angel";
	m_hostesses[0].m_statsAndTraits.m_stats = { 100, 40, 23, 11, 51 };
	m_hostesses[0].m_statsAndTraits.m_traits = {10, 10, 10, 10};

	m_hostesses[1].m_image = LoadTexture("resources/Images/fullBodyGirls/Clara.png");
	m_hostesses[1].m_faceImage = LoadTexture("resources/Images/faceOnlyGirls/Clara-Head.png");
	m_hostesses[1].m_name = "Clara";
	m_hostesses[1].m_statsAndTraits.m_stats = { 100, 40, 23, 11, 51 };
	m_hostesses[1].m_statsAndTraits.m_traits = {10, 10, 10, 10};

}
