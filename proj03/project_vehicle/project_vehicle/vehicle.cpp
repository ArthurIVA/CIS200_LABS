/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/15/18
*/
#include "vehicle.h"

//Default Constructor
vehicle::vehicle()
{
	age = 0;
	price = 0.0;
	heading = "North";
	isStarted = false;
}

//Setter Commands
void vehicle::setAge(int a)
{
	if (a >= 0)
	{
		age = a;
	}
	else
	{
		std::cout << "INVALID VEHICLE AGE" << std::endl;
	}
}

void vehicle::setPrice(float p)
{
	if (p >= 0.00)
	{
		price = p;
	}
	else
	{
		std::cout << "INVALID VEHICLE PRICE" << std::endl;
	}
}

void vehicle::setHeading(std::string input)
{
	heading = input;
}

void vehicle::setIsStarted(bool input)
{
	isStarted = input;
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

std::string vehicle::getHeading()
{
	return heading;
}

bool vehicle::getIsStarted()
{
	return isStarted;
}

void vehicle::start()
{
	setIsStarted(true);
}

void vehicle::turnOff()
{
	setIsStarted(false);
}

//Other Commands
void vehicle::moveNorth()
{
	setHeading("North");
	std::cout << "Moved North" << std::endl;
}

void vehicle::moveSouth()
{
	setHeading("South");
	std::cout << "Moved South" << std::endl;
}

void vehicle::moveEast()
{
	setHeading("East");
	std::cout << "Moved East" << std::endl;
}

void vehicle::moveWest()
{
	setHeading("West");
	std::cout << "Moved West" << std::endl;
}

void vehicle::printVehicleInfo()
{
	std::cout << std::endl;
	std::cout << "All Vehicle Info" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Model Year: " << getAge() << std::endl;
	std::cout << "Price:  " << getPrice() << std::endl;
	std::cout << "Current Heading: " << getHeading() << std::endl;
	std::cout << "Vehicle Running: ";
	
	if (getIsStarted() == true)
	{
		std::cout << "Running" << std::endl;
	}
	else
	{
		std::cout << "Not Running" << std::endl;
	}
}

//UNECCESARY
void vehicle::printVehicleOptions()
{
}
