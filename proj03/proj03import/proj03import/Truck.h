#pragma once
#include"Vehicle.h"
/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/
class Truck : public Vehicle
{
public:
	Truck();
	void setDieselStatus(bool s);
	bool getDieselTypeStatus();
private:
	bool DieselTypeStatus;
};
