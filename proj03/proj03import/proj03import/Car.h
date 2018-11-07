#pragma once
#include "Vehicle.h"
/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/
class Car : public Vehicle
{
public:
	Car();
	void setRaceCarStatus(bool s);
	bool getRaceCarStatus();
private:
	bool RaceCarStatus;

};