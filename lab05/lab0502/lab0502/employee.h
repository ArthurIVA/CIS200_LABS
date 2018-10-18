#pragma once
#include <iostream>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee
{
private:
	int age;
	int id;
	float salary;

public:
	employee();		//Default Constructor

	//Setter Commands
	void setAge(int);
	void setID(int);
	void setSalary(float);

	//Getter Commands
	int getAge();
	int getID();
	float getSalary();

	~employee();	//Default Destructor
};
#endif EMPLOYEE_H