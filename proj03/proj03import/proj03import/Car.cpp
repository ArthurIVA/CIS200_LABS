#include "Car.h"
# include <iostream>
/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/
Car::Car()
{
	RaceCarStatus = false;
}
void Car::setRaceCarStatus(bool s)
{
	RaceCarStatus = s;
}
bool Car::getRaceCarStatus()
{
	return RaceCarStatus;
}