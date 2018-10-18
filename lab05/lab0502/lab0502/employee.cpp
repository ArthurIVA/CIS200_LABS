#include "employee.h"


//Default Constructor
employee::employee()
{
	age = 0;
	id = 0;
	salary = 0.0;
}

//Setter Commands
void employee::setAge(int input)
{
	if (input > 0)
	{
		age = input;
	}
	else
	{
		std::cout << "Invalid Age" << std::endl;
	}
}

void employee::setID(int input)
{
	if (input > 0)
	{
		id = input;
	}
	else
	{
		std::cout << "Invalid ID" << std::endl;
	}
}

void employee::setSalary(float input)
{
	if (input >= 0)
	{
		salary = input;
	}
	else
	{
		std::cout << "Invalid Salary" << std::endl;
	}
}

//Getter Commands
int employee::getAge()
{
	return age;
}

int employee::getID()
{
	return id;
}

float employee::getSalary()
{
	return salary;
}

//Default Destructor
employee::~employee()
{
}
