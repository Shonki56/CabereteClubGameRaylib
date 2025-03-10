#pragma once
#include <raylib.h>
#include <vector>
#include "Hostess.hpp"
#include "Sofa.h"
#include "SofaManager.hpp";

class HostessManager
{
public:
	HostessManager();
	void unselectAllHostesses();
	bool isAHostessCurrentlySelected();
	void handleSelectingHostesses();
	void handlePlacingHostesses(SofaManager& sofaManager);
	int getTotalMoneyMade();
	Hostess m_hostesses[4];
	Hostess m_selectedHostess;
private:
	void placeHostess(Hostess& hostess, Sofa& sofa);
	void removeHostess(Hostess& hostess, Sofa& sofa);
	void initHostesses();


};
