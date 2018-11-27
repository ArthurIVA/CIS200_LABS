/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/15/18
*/

///UPDATED INFORMATION
//Class: Vehicle
//Edited By: Arthur Aigeltinger IV
//Description: ^^^
//Date Modified: 11/26/18

//Major Changes
/*
Changed "Vehicle" to "vehicle" for class consistency
Included "string" class to introduce "heading"
*/
#pragma once

#include <iostream>
#include <string>

#ifndef VEHICLE_H
#define VEHICLE_H

class vehicle
{
public:
	//Default Constructor
	vehicle();

	//Setter Commands
	void setAge(int a);
	void setPrice(float p);
	void setHeading(std::string input);
	void setIsStarted(bool input);

	//Getter Commands
	int getAge();
	float getPrice();
	std::string getHeading();
	bool getIsStarted();

	//Other/Control Commands
	void start();
	void turnOff();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void printVehicleInfo();
	void printVehicleOptions();

private:
	int age;
	float price;
	std::string heading;
	bool isStarted;
};
#endif