#include "car.h"

//Default Constructor
car::car()
{
	RaceCarStatus = 0;
}

//Setter
void car::setRaceCarStatus(bool input)
{
	RaceCarStatus = input;
}

//Getter
bool car::getRaceCarStatus()
{
	return RaceCarStatus;
}

//Default Destructor
car::~car()
{
}
