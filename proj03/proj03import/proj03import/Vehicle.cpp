/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/15/18
*/
#include<iostream>
#include "Vehicle.h"
Vehicle::Vehicle()
{
	age = 0;
	price = 0.0;
}
void Vehicle::setAge(int a)
{
	age=a;
}
void Vehicle::setPrice(float p)
{
	price=p;
}
int Vehicle::getAge()
{
	return age;
}
float Vehicle::getPrice()
{
	return price;
}