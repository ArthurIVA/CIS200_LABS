#pragma once
#include "vehicle.h"

#ifndef BOAT_H
#define	BOAT_H

class boat : public vehicle
{
public:
	//Default Constructor
	boat();

	//Setter Commands
	void setIsDocked(bool input);
	void setFlagRaised(bool input);
	
	//Getter Commands
	bool getIsDocked();
	bool getFlagRasied();

	//Other Commands
	void toggleFlag();
	bool undock();
	bool dock();
	void printBoatInfo();
	void printBoatOptions();
	bool moveNorth();
	bool moveSouth();
	bool moveEast();
	bool moveWest();

private:
	bool isDocked;
	bool flagRasied;
};
#endif