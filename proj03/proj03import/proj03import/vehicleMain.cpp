/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/17/18
*/
/*This just Test Vehicle*/
#include "Vehicle.h"
#include<iostream>
using namespace std;
int main()
{
	Vehicle a;
	a.setAge(25);
	a.setPrice(10.00);
	cout << "The age of the car A is " << a.getAge() << "" << "the car price is " << a.getPrice() << endl;
	Vehicle b;
	cout << "The age of the car B is " << b.getAge() << "" << "the car price is " << b.getPrice() << endl;
	system("pause");
	return 0;
}