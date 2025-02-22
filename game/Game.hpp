#pragma once
#include <raylib.h>
#include <Sofa.h>
#include <vector>
#include <Hostess.hpp>

class Game
{
public:
	Game();
	void Draw();
	void Update();
	void HandleInputs();
	void placeHostess(Hostess& hostess, Sofa& sofa);
	std::vector<Sofa> m_sofas;
private:
	void InitGame();
	std::vector<Sofa> CreateSofas();
	//std::vector<Hostess> m_hostesses;
	Hostess m_hostesses[2];
	void displayHostessesFaces();
	void handleSelectingHostesses();
	void initHostesses();
	bool isAHostessCurrentlySelected();
	void handlePlacingHostess();
	void unselectAllHostesses();

};
