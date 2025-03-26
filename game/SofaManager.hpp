#pragma once
#include <raylib.h>
#include "Sofa.h"
#include <vector>

class SofaManager
{
public:
	SofaManager();
	std::vector<Sofa> m_sofas;
	int checkIfASofaIsFree();
	void freeEmptySofas();
private:
	void fillSofasVector();
	void freeSingleSofa(Sofa& sofa);

};
