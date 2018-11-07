/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance
DATE CREATED:10/17/18
*/
/*This test vehicle and car*/
#include <iostream>
#include "Car.h"
using namespace std;
int main()
{
	//Car c;
	//c.setAge(25);
	//c.setPrice(3000);
	//c.setRaceCarStatus(true);
	//cout << "The age of the car C is " << c.getAge() << "" << "the car price is " << c.getPrice() << "" << "The race car status is" << c.getRaceCarStatus() << endl;
	Car d;
	cout << "The age of the car D is " << d.getAge() << "" << "the car price is " << d.getPrice() << "" << "The race car status is" << d.getRaceCarStatus() << endl;
	system("pause");
	return 0;
}