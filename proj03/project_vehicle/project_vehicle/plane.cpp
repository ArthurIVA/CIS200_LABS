#include "plane.h"

plane::plane()
{
	liftoffStatus = false;
	altitude = 0;
}

//Setter Commands
void plane::setLiftoffStatus(bool input)
{
	liftoffStatus = input;
}

void plane::setAltitude(int input)
{
	if (input >= 0)
	{
		altitude = input;
	}
	else
	{
		std::cout << "INVALID ALTITUDE" << std::endl;
	}
}

//Getter Commands
bool plane::getLiftoffStatus()
{
	return liftoffStatus;
}

int plane::getAltitude()
{
	return altitude;
}

bool plane::takeoff()
{
	if (getIsStarted() == true)
	{
		if (getLiftoffStatus() == false && altitude == 0)
		{
			setLiftoffStatus(true);
			setAltitude(1);
			std::cout << "Plane Took Off" << std::endl;
			std::cout << "Ascended To " << getAltitude() << " Thousand Feet" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Plane Already Taken Off" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Plane Not Started" << std::endl;
		return false;
	}
}

bool plane::ascend()
{
	if (getIsStarted() == true && getLiftoffStatus() == true)
	{
		if (getAltitude() < 15)
		{
			setAltitude(getAltitude() + 1);
			std::cout << "Ascended by 1 Thousand Feet" << std::endl;
			return true;
		}
		else
		{
			std::cout << "You Cannot Fly That High" << std::endl;
			return false;
		}
	}
	else if (getIsStarted() == true && getLiftoffStatus() == false)
	{
		std::cout << "You Must Take Off First" << std::endl;
		return false;
	}
	else
	{
		std::cout << "You Must Start The Plane First" << std::endl;
		return false;
	}
}

bool plane::descend()
{
	if (getIsStarted() == true && getLiftoffStatus() == true)
	{
		if (getAltitude() > 1)
		{
			setAltitude(getAltitude() - 1);
			std::cout << "Descended by 1 Thousand Feet" << std::endl;
			return true;
		}
		else
		{
			std::cout << "You Cannot Fly Lower, Please Land Instead" << std::endl;
			return false;
		}
	}
	else if (getIsStarted() == true && getLiftoffStatus() == false)
	{
		std::cout << "You Must Take Off First" << std::endl;
		return false;
	}
	else
	{
		std::cout << "You Must Start The Plane First" << std::endl;
		return false;
	}
}

bool plane::land()
{
	if (getAltitude() > 0)
	{
		setLiftoffStatus(false);
		setAltitude(0);
		std::cout << "Plane Landing From Current Altitude" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Already Landed" << std::endl;
		return false;
	}
}

void plane::printPlaneInfo()
{
	printVehicleInfo();
	std::cout << "Flight Status: ";

	if (getLiftoffStatus())
	{
		std::cout << "In Flight" << std::endl;
		std::cout << "Altitude: " << getAltitude() << " Thousand Feet" << std::endl;
	}
	else
	{
		std::cout << "Landed" << std::endl;
		std::cout << "Altitude : 0 Feet" << std::endl;
	}
}

void plane::printPlaneOptions()
{
	std::cout << "Plane Controls" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "(I) Print Plane Information" << std::endl;
	std::cout << "(O) Print Plane Options / Controls" << std::endl;
	std::cout << "(T) Take Off" << std::endl;
	std::cout << "(L) Land" << std::endl;
	std::cout << "(A) Ascend" << std::endl;
	std::cout << "(D) Descend" << std::endl;
	std::cout << "(N) Fly North" << std::endl;
	std::cout << "(S) Fly South" << std::endl;
	std::cout << "(E) Fly East" << std::endl;
	std::cout << "(W) Fly West" << std::endl;
	std::cout << "(Q) Exit Vehicle" << std::endl;
}

bool plane::moveNorth()
{
	if (getIsStarted() == false)
	{
		std::cout << "Plane is NOT Started" << std::endl;
		return false;
	}
	else if (getLiftoffStatus() == false)
	{
		std::cout << "Plane is still landed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Flew North" << std::endl;
		setHeading("North");
		return true;
	}
}

bool plane::moveSouth()
{
	if (getIsStarted() == false)
	{
		std::cout << "Plane is NOT Started" << std::endl;
		return false;
	}
	else if (getLiftoffStatus() == false)
	{
		std::cout << "Plane is still landed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Flew South" << std::endl;
		setHeading("South");
		return true;
	}
}

bool plane::moveEast()
{
	if (getIsStarted() == false)
	{
		std::cout << "Plane is NOT Started" << std::endl;
		return false;
	}
	else if (getLiftoffStatus() == false)
	{
		std::cout << "Plane is still landed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Flew East" << std::endl;
		setHeading("East");
		return true;
	}
}

bool plane::moveWest()
{
	if (getIsStarted() == false)
	{
		std::cout << "Plane is NOT Started" << std::endl;
		return false;
	}
	else if (getLiftoffStatus() == false)
	{
		std::cout << "Plane is still landed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Flew West" << std::endl;
		setHeading("West");
		return true;
	}
}
