#include "vehicle.h"

//Default Constructor
vehicle::vehicle()
{
	age = 0;
	price = 0.0;
}

//Setter Commands
void vehicle::setAge(int input)
{
	age = input;
}

void vehicle::setPrice(float input)
{
	price = input;
}

//Getter Commands
int vehicle::getAge()
{
	return age;
}

float vehicle::getPrice()
{
	return price;
}

//Default Destructor
vehicle::~vehicle()
{
}
