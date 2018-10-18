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
	if (input >= 0)
	{
		age = input;
	}
	else
	{
		std::cout << "Invalid Age" << std::endl;
	}
}

void vehicle::setPrice(float input)
{
	if (input >= 0)
	{
		price = input;
	}
	else
	{
		std::cout << "Invalid Price" << std::endl;
	}
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
