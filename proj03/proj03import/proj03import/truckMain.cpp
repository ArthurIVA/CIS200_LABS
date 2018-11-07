/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/17/18
*/
//TEST THE TRUCK CLASS
#include<iostream>
#include "Truck.h"
using namespace std;
int main()
{
	Truck e;
	e.setDieselStatus(true);
	cout << "The race car status is" << e.getDieselTypeStatus() << endl;
	Truck f;
	cout <<  "The race car status is" << f.getDieselTypeStatus() << endl;
	system("pause");
	return 0;
}