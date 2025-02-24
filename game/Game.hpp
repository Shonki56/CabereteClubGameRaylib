#pragma once
#include <raylib.h>
#include <Sofa.h>
#include <vector>
#include <Hostess.hpp>
#include "raymath.h"
#include "lib.h"
#include "Gui.hpp"
#include "Client.hpp"

class Game
{
public:
	Game();
	void Draw();
	void Update();
	void HandleInputs();
	void placeHostess(Hostess& hostess, Sofa& sofa);
	std::vector<Sofa> m_sofas;
	void placeClient(Client& client);
	float m_lastSpawnTime;
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
	void generateClient();
	void spawnClient();
	std::vector<Client> m_clients;
	int checkIfSofaIsFree();
	bool clientTimeout(const Client& client);
	void removeClient();

};
