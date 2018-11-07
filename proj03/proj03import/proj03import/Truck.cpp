/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/16/18
*/
#include "Truck.h"
Truck::Truck()
{
	DieselTypeStatus =  false;
}
void Truck::setDieselStatus(bool s)
{
	DieselTypeStatus = s;
}
bool Truck::getDieselTypeStatus()
{
	return DieselTypeStatus;
}