/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/
#include "truck.h"

//Default Constructor
truck::truck()
{
	dieselTypeStatus = false;
	fwdStatus = false;
}

//Setter Commands
void truck::setDieselStatus(bool s)
{
	dieselTypeStatus = s;
}

void truck::setFwdStatus(bool input)
{
	fwdStatus = input;
}

//Getter Commands
bool truck::getDieselTypeStatus()
{
	return dieselTypeStatus;
}

bool truck::getFwdStatus()
{
	return fwdStatus;
}


//Other Commands
void truck::toggleFWD()
{
	if (getFwdStatus() == true)
	{
		setFwdStatus(false);
		std::cout << "Four Wheel Drive Disabled" << std::endl;
	}
	else
	{
		setFwdStatus(true);
		std::cout << "Four Wheel Drive Enabled" << std::endl;
	}
}

void truck::exchangeCornOil()
{
	if (getDieselTypeStatus() == true)
	{
		std::cout << "Silly Goose, You Can't Reverse That!" << std::endl;
	}
	else
	{
		setDieselStatus(true);
		std::cout << "You're Running On Diesel Now. Go Roll Some Coal!" << std::endl;
		std::cout << "just kidding, don't do that, its a richard move" << std::endl;
	}
}

void truck::printTruckInfo()
{
	printLandVehicleInfo();
	std::cout << "Fuel Type: ";

	if (getDieselTypeStatus() == true)
	{
		std::cout << "Yee Haw Diesel" << std::endl;
	}
	else
	{
		std::cout << "Gasoline" << std::endl;
	}
	std::cout << "4WD Status: ";

	if (getFwdStatus())
	{
		std::cout << "Active" << std::endl;
	}
	else
	{
		std::cout << "Inactive" << std::endl;
	}
}

void truck::printTruckOptions()
{
	std::cout << "Truck Controls" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "(I) Print Truck Information" << std::endl;
	std::cout << "(O) Print Truck Options / Controls" << std::endl;
	std::cout << "(C) Exchange Corn Oil" << std::endl;
	std::cout << "(F) Toggle 4WD" << std::endl;
	std::cout << "(U) Toggle Windshield Wipers" << std::endl;
	std::cout << "(P) Shift Into Park" << std::endl;
	std::cout << "(D) Shift Into Drive" << std::endl;
	std::cout << "(N) Drive North" << std::endl;
	std::cout << "(S) Drive South" << std::endl;
	std::cout << "(E) Drive East" << std::endl;
	std::cout << "(W) Drive West" << std::endl;
	std::cout << "(Q) Exit Vehicle" << std::endl;
}