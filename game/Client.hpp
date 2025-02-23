#pragma once
#include <raylib.h>
#include "Hostess.hpp"

enum clientHappiness{ NOT, LITTLE, MEDIUM, MUCH, VERYMUCH }; 
enum clientType{POOR, AVERAGE, RICH, MEGARICH};
class Client
{
public:
	Client(clientType clientType);
	~Client();
	Texture2D m_clientImage;
	void Draw();
	void Update();
	clientHappiness howMuchDoesClientLikeHostess(Hostess& hostess);
	clientType m_type;
	void getCorrectType();
private:

};
