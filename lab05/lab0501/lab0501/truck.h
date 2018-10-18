#pragma once
#include "vehicle.h"

#ifndef TRUCK_H
#define TRUCK_H

class truck: public vehicle
{
public:
	truck();		//Default Constructor

	void setDieselTypeStatus(bool);
	bool getDieselTypeStatus();
		
	~truck();		//Default Destructor
protected:
	bool DieselTypeStatus;
};


#endif TRUCK_H