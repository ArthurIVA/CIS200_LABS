#pragma once
#include "vehicle.h"

#ifndef LANDVEHICLE_H
#define	LANDVEHICLE_H

class landVehicle : public vehicle
{
public:
	//Default Constructor
	landVehicle();

	//Setter Commands
	void setNumPassengers(int input);
	void setIsParked(bool input);
	void setWindshieldWiperStatus(bool input);

	//Getter Commands
	int getNumPassengers();
	bool getIsParked();
	bool getWindshieldWiperStatus();

	//Other Commands
	void toggleWindshieldWipers();
	void park();
	void drive();
	void printLandVehicleInfo();
	void printLandVehicleOptions();
	bool moveNorth();
	bool moveSouth();
	bool moveEast();
	bool moveWest();

private:
	int numPassengers;
	bool isParked;
	bool windshieldWiperStatus;
};
#endif 