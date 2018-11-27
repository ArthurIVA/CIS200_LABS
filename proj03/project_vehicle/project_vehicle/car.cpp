#include "car.h"
/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/

//Default Constructor
car::car()
{
	RaceCarStatus = false;
	radioStatus = false;
}

//Setter Commands
void car::setRaceCarStatus(bool s)
{
	RaceCarStatus = s;
}

void car::setRadioStatus(bool input)
{
	radioStatus = input;
}

//Getter Commands
bool car::getRaceCarStatus()
{
	return RaceCarStatus;
}

bool car::getRadioStatus()
{
	return radioStatus;
}


//Other Commands
void car::toggleRadio()
{
	if (getRadioStatus() == true)
	{
		setRadioStatus(false);
		std::cout << "Radio Turned Off" << std::endl;
	}
	else
	{
		setRadioStatus(true);
		std::cout << "Radio Turned On" << std::endl;
		std::cout << "NEVER GONNA GIVE YOU UP!" << std::endl;
		std::cout << "NEVER GONNA LET YOU DOWN!" << std::endl;
		std::cout << "NEVER GONNA TURN AROUND..." << std::endl;
		std::cout << "AND HURT YOU......." << std::endl;
	}
}

void car::toggleSpoiler()
{
	if (getRaceCarStatus() == true)
	{
		setRaceCarStatus(false);
		std::cout << "Spoiler Lowered" << std::endl;
	}
	else
	{
		setRaceCarStatus(true);
		std::cout << "Spoiler Raised" << std::endl;
	}
}

void car::printCarInfo()
{
	printLandVehicleInfo();
	std::cout << "Spoiler: ";

	if (getRaceCarStatus() == true)
	{
		std::cout << "Raised" << std::endl;
	}
	else
	{
		std::cout << "Lowered" << std::endl;
	}
}

void car::printCarOptions()
{
	std::cout << "Car Controls" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "(I) Print Car Information" << std::endl;
	std::cout << "(O) Print Car Options / Controls" << std::endl;
	std::cout << "(R) Toggle Radio" << std::endl;
	std::cout << "(J) Toggle Spoiler / JDM Mode" << std::endl;
	std::cout << "(U) Toggle Windshield Wipers" << std::endl;
	std::cout << "(P) Shift Into Park" << std::endl;
	std::cout << "(D) Shift Into Drive" << std::endl;
	std::cout << "(N) Drive North" << std::endl;
	std::cout << "(S) Drive South" << std::endl;
	std::cout << "(E) Drive East" << std::endl;
	std::cout << "(W) Drive West" << std::endl;
	std::cout << "(Q) Exit Vehicle" << std::endl;
}
