/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/15/18
*/
#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
class Vehicle
{
public:
	Vehicle();
	void setAge(int a);
	void setPrice(float p);
	int getAge();
	float getPrice();
private:
	int age;
	float price;
};
#endif