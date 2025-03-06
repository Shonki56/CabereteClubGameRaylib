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
	Hostess m_hostesses[2];
private:
	void initHostesses();


};
