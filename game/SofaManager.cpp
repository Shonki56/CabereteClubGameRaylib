#include "SofaManager.hpp"

void SofaManager::fillSofasVector()
{
	int offsetX = 400;
	int offsetY = 150;
	for (int row = 0; row < 2; ++row)
	{
		for (int column = 0; column < 2; ++column)
		{
			float x = offsetX + column * 350;
			float y = offsetY + row * 360;
			Sofa newSofa({ x, y });
			m_sofas.push_back(newSofa);
		}
	}
}

void SofaManager::freeSingleSofa(Sofa& sofa)// attempting to run this even though
{
	sofa.m_isBeingUsed = false;
	sofa.m_isBeingUsedByClientAndHostess = false;
	sofa.m_currentSituation = nullptr; 
	if (sofa.m_currentHostess != nullptr)
	{
		sofa.m_currentHostess->m_isBeingUsed = false;
		sofa.m_currentHostess = nullptr;
	}
}

SofaManager::SofaManager()
{
	fillSofasVector();
}

int SofaManager::checkIfASofaIsFree()
{
	for (int i = 0; i < m_sofas.size(); i++)
	{
		if (m_sofas[i].m_currentClient == nullptr)
		{
			return i;
			break;
		}
		else
		{
			std::cout << "Sofa " << i << " is currently being used\n";
		}

	}

	std::cout << "No free sofa found!\n";
	return -1;

}

void SofaManager::freeEmptySofas()
{
	for (Sofa& sofa : m_sofas)
	{
		if (sofa.m_isBeingUsedByClient == false)
		{
			freeSingleSofa(sofa);
		}
	}
}

void SofaManager::clearAllSituations()
{
	for (auto& sofa : m_sofas)
	{
		sofa.clearSituation();
	}
}
