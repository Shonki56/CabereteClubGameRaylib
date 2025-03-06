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
	Hostess m_hostesses[2];
	Hostess m_selectedHostess;
private:
	void placeHostess(Hostess& hostess, Sofa& sofa);
	void removeHostess(Hostess& hostess, Sofa& sofa);
	void initHostesses();


};
