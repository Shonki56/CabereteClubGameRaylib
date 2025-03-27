#include "SituationInterface.hpp"

void SituationInterface::createRectsForButtons(int amountOfButtons, std::vector<std::string> choiceNames)
{
	Vector2 startPosition = { 100, 100 };
	const Vector2 buttonSize = { 100, 100 };
	const double amountToAddToButtonY = 100;
	for (int i = 0; i < amountOfButtons; i++)
	{
		Rectangle rec{ startPosition.x, startPosition.y + amountToAddToButtonY * i, 300, 60 };
		if (GuiButton(rec, choiceNames[1].c_str()))
		{

		}
	}
}
