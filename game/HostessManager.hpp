#pragma once
#include <raylib.h>
#include <vector>
#include "Hostess.hpp"
#include "Sofa.h"

class HostessManager
{
public:
	HostessManager();
	void placeHostess(Hostess& hostess, Sofa& sofa);
	void removeHostess(Hostess& hostess, Sofa& sofa);
	void unselectAllHostesses();
	bool isAHostessCurrentlySelected();
	void handleSelectingHostesses();
	Hostess m_hostesses[2];
	Hostess m_selectedHostess;
private:
	void initHostesses();


};
