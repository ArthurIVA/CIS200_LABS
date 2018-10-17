#pragma once

#ifndef VEHICLE_H
#define VEHICLE_H

class vehicle
{
public:

	vehicle();		//Default Constructor Primitive

	void setAge(int);
	void setPrice(float);

	int getAge();
	float getPrice();

	~vehicle();		//Default Constrcutor Primitive

private:

	int age;		//Age of the vehicle
	float price;	//Price of the vehicle
};
#endif VEHICLE_H