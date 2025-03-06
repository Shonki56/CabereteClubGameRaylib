#include "HostessManager.hpp"

HostessManager::HostessManager()
{
	initHostesses();
}

void HostessManager::placeHostess(Hostess& hostess, Sofa& sofa)
{

	hostess.m_position = sofa.m_position;
	hostess.m_position.y -= 50;
	sofa.m_isBeingUsed = true;
	hostess.m_isBeingUsed = true;
	hostess.m_isCurrentlySelected = false;
	sofa.m_currentHostess = &hostess;

}

void HostessManager::removeHostess(Hostess& hostess, Sofa& sofa)
{
	sofa.m_isBeingUsed = false;
	hostess.m_isBeingUsed = false;
	sofa.m_currentHostess = nullptr;
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
