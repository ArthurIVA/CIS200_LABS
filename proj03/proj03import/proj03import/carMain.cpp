/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/17/18

THIS TEST CAR CLASS*/
#include <iostream>
#include "Car.h"
using namespace std;
int main()
{
	Car c;
	c.setRaceCarStatus(true);
	cout << "The race car status is" << c.getRaceCarStatus() << endl;
	Car d;
	cout << "The race car status is" << d.getRaceCarStatus()<<endl;
	system("pause");
	return 0;
}