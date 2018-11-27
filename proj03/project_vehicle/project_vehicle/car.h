#pragma once
#include "landVehicle.h"
/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/

#ifndef CAR_H
#define	CAR_H

class car : public landVehicle
{
public:
	//Default Constructor
	car();

	//Setter Commands
	void setRaceCarStatus(bool s);
	void setRadioStatus(bool input);

	//Getter Commands
	bool getRaceCarStatus();
	bool getRadioStatus();

	//Other Commands
	void toggleRadio();
	void toggleSpoiler();
	void printCarInfo();
	void printCarOptions();

private:
	bool RaceCarStatus;
	bool radioStatus;
};
#endif