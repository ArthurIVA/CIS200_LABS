#include "truck.h"

//Default Constructor
truck::truck()
{
	DieselTypeStatus = false;
}

//Setter
void truck::setDieselTypeStatus(bool input)
{
	DieselTypeStatus = input;
}

//Getter
bool truck::getDieselTypeStatus()
{
	return DieselTypeStatus;
}

//Default Destructor
truck::~truck()
{

}


