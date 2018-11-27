#include "landVehicle.h"

//Default Constructor
landVehicle::landVehicle()
{
	numPassengers = 1;
	isParked = true;
	windshieldWiperStatus = false;
}

//Setter Commands
void landVehicle::setNumPassengers(int input)
{
	if (input >= 1 && input <= 4)
	{
		numPassengers = input;
	}
	else
	{
		std::cout << "INVALID NUMBER OF PASSENGERS" << std::endl;
	}
}

void landVehicle::setIsParked(bool input)
{
	isParked = input;
}

void landVehicle::setWindshieldWiperStatus(bool input)
{
	windshieldWiperStatus = input;
}

//Getter Commands
int landVehicle::getNumPassengers()
{
	return numPassengers;
}

bool landVehicle::getIsParked()
{
	return isParked;
}

bool landVehicle::getWindshieldWiperStatus()
{
	return windshieldWiperStatus;
}


//Other Commands
void landVehicle::toggleWindshieldWipers()
{
	if (getWindshieldWiperStatus() == true)
	{
		setWindshieldWiperStatus(false);
		std::cout << "Wipers Turned Off" << std::endl;
	}
	else
	{
		setWindshieldWiperStatus(true);
		std::cout << "Wipers Turned On" << std::endl;
	}
}

void landVehicle::park()
{
	std::cout << "Shifted Into Park" << std::endl;
	setIsParked(true);
}

void landVehicle::drive()
{
	std::cout << "Shifted Into Drive" << std::endl;
	setIsParked(false);
}

void landVehicle::printLandVehicleInfo()
{
	printVehicleInfo();
	std::cout << "Passengers: " << getNumPassengers() << std::endl;
	std::cout << "Gear: ";

	if (getIsParked() == true) 
	{
		std::cout << "Parked" << std::endl;
	}
	else
	{
		std::cout << "Drive" << std::endl;
	}
}

void landVehicle::printLandVehicleOptions()
{

}

bool landVehicle::moveNorth()
{
	if (getIsStarted() == false)
	{
		std::cout << "Vehicle is NOT Started" << std::endl;
		return false;
	}
	else if (getIsParked() == true)
	{
		std::cout << "Vehicle is still in PARK" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Drove North" << std::endl;
		setHeading("North");
		return true;
	}
}

bool landVehicle::moveSouth()
{
	if (getIsStarted() == false)
	{
		std::cout << "Vehicle is NOT Started" << std::endl;
		return false;
	}
	else if (getIsParked() == true)
	{
		std::cout << "Vehicle is still in PARK" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Drove South" << std::endl;
		setHeading("South");
		return true;
	}
}

bool landVehicle::moveEast()
{
	if (getIsStarted() == false)
	{
		std::cout << "Vehicle is NOT Started" << std::endl;
		return false;
	}
	else if (getIsParked() == true)
	{
		std::cout << "Vehicle is still in PARK" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Drove East" << std::endl;
		setHeading("East");
		return true;
	}
}

bool landVehicle::moveWest()
{
	if (getIsStarted() == false)
	{
		std::cout << "Vehicle is NOT Started" << std::endl;
		return false;
	}
	else if (getIsParked() == true)
	{
		std::cout << "Vehicle is still in PARK" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Drove West" << std::endl;
		setHeading("West");
		return true;
	}
}