#include "boat.h"

boat::boat()
{
	isDocked = true;
	flagRasied = false;
}

//Setter Commands
void boat::setIsDocked(bool input)
{
	isDocked = input;
}

void boat::setFlagRaised(bool input)
{
	flagRasied = input;
}

//Getter Commands
bool boat::getIsDocked()
{
	return isDocked;
}

bool boat::getFlagRasied()
{
	return flagRasied;
}

//Other Commands
void boat::toggleFlag()
{
	if (getFlagRasied() == true)
	{
		setFlagRaised(false);
		std::cout << "Flag Lowered" << std::endl;
	}
	else
	{
		setFlagRaised(true);
		std::cout << "Flag Raised" << std::endl;
	}
}

bool boat::undock()
{
	if (getIsDocked() == true)
	{
		std::cout << "Un-Docked" << std::endl;
		setIsDocked(false);
		return true;
	}
	else
	{
		std::cout << "You Are Already Un-Docked" << std::endl;
		return false;
	}
}

bool boat::dock()
{
	if (getIsDocked() == false)
	{
		std::cout << "Docked" << std::endl;
		setIsDocked(true);
		return true;
	}
	else
	{
		std::cout << "You Are Already Docked" << std::endl;
		return false;
	}
}

void boat::printBoatInfo()
{
	printVehicleInfo();
	std::cout << "Docked Status: ";

	if (getIsDocked() == true)
	{
		std::cout << "Docked" << std::endl;
	}
	else
	{
		std::cout << "Un-Docked" << std::endl;
	}

	std::cout << "Flag: ";

	if (getFlagRasied() == true)
	{
		std::cout << "Rasied" << std::endl;
	}
	else
	{
		std::cout << "Lowered" << std::endl;
	}
}

void boat::printBoatOptions()
{
	std::cout << "Boat Controls" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "(I) Print Boat Information" << std::endl;
	std::cout << "(O) Print Boat Options / Controls" << std::endl;
	std::cout << "(F) Toggle Flag" << std::endl;
	std::cout << "(U) Un-Dock" << std::endl;
	std::cout << "(D) Dock" << std::endl;
	std::cout << "(N) Sail North" << std::endl;
	std::cout << "(S) Sail South" << std::endl;
	std::cout << "(E) Sail East" << std::endl;
	std::cout << "(W) Sail West" << std::endl;
	std::cout << "(Q) Exit Vehicle" << std::endl;
}

bool boat::moveNorth()
{
	if (getIsStarted() == false)
	{
		std::cout << "Boat is NOT Started" << std::endl;
		return false;
	}
	else if (getIsDocked() == true)
	{
		std::cout << "Boat is still docked" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Sailed North" << std::endl;
		setHeading("North");
		return true;
	}
}

bool boat::moveSouth()
{
	if (getIsStarted() == false)
	{
		std::cout << "Boat is NOT Started" << std::endl;
		return false;
	}
	else if (getIsDocked() == true)
	{
		std::cout << "Boat is still docked" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Sailed South" << std::endl;
		setHeading("South");
		return true;
	}
}

bool boat::moveEast()
{
	if (getIsStarted() == false)
	{
		std::cout << "Boat is NOT Started" << std::endl;
		return false;
	}
	else if (getIsDocked() == true)
	{
		std::cout << "Boat is still docked" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Sailed East" << std::endl;
		setHeading("East");
		return true;
	}
}

bool boat::moveWest()
{
	if (getIsStarted() == false)
	{
		std::cout << "Boat is NOT Started" << std::endl;
		return false;
	}
	else if (getIsDocked() == true)
	{
		std::cout << "Boat is still docked" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Sailed West" << std::endl;
		setHeading("West");
		return true;
	}
}