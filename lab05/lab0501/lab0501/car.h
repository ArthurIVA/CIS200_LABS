#pragma once
#include <iostream>
#include "vehicle.h"

#ifndef CAR_H
#define CAR_H

class car: public vehicle
{
public:

	car();		//Default Constructor

	void setRaceCarStatus(bool);
	bool getRaceCarStatus();

	~car();		//Default Destructor
protected:

	bool RaceCarStatus;
};

#endif CAR_H