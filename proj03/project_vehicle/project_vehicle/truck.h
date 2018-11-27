#pragma once
#include "landVehicle.h"
/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/

#ifndef TRUCK_H
#define	TRUCK_H

class truck : public landVehicle
{
public:
	//Default Constructor
	truck();

	//Setter Commands
	void setDieselStatus(bool s);
	void setFwdStatus(bool input);

	//Getter Commands
	bool getDieselTypeStatus();
	bool getFwdStatus();

	//Other Commands
	void toggleFWD();
	void exchangeCornOil();
	void printTruckInfo();
	void printTruckOptions();

private:
	bool dieselTypeStatus;
	bool fwdStatus;
};
#endif