#pragma once
#include "vehicle.h"

#ifndef PLANE_H
#define	PLANE_H

class plane : public vehicle
{
public:
	//Default Constructor 
	plane();

	//Setter Commands
	void setLiftoffStatus(bool input);
	void setAltitude(int input);
	
	//Getter Commands
	bool getLiftoffStatus();
	int getAltitude();

	//Other Commands
	bool takeoff();
	bool ascend();
	bool descend();
	bool land();
	void printPlaneInfo();
	void printPlaneOptions();
	bool moveNorth();
	bool moveSouth();
	bool moveEast();
	bool moveWest();


private:
	bool liftoffStatus;
	int altitude;
};
#endif