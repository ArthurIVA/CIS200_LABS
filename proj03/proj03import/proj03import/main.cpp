/*PROGRAM: LAB 5
PROGRAMMER: SHERRY ROBBINS
DESCRIPTION:Create a program that use parent-child classes & inheritance 
DATE CREATED:10/15/18
*/
#include<iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
/*This main test everything(VEHICLE CAR & TRUCK)*/
using namespace std;
int main()
{

	Vehicle a;
	a.setAge(30);
	a.setPrice(6.00);
	
	cout << "VEHICLE CLASS" << endl;
	cout << "The age of the car A is " << a.getAge() << "" << ". The car price is " << a.getPrice() << endl;
	Vehicle b;
	cout << "The age of the car B is " << b.getAge() << "" << ". The car price is " << b.getPrice() << endl;
	
	Car c;
	c.setAge(30);
	c.setPrice(6.00);
	c.setRaceCarStatus(true);
	cout << "CAR CLASS" << endl;
	cout << "The age of the car C is " << c.getAge() << "" << ". The car price is " << c.getPrice() <<""<<". The race car status is "<<c.getRaceCarStatus()<< endl;
	Car d;
	cout << "The age of the car D is " << d.getAge() << "" << ". The car price is " << d.getPrice() << "" << ". The race car status is " << d.getRaceCarStatus() << endl;
	
	Truck e;
	e.setAge(30);
		e.setPrice(6.00);
	e.setDieselStatus(true);
	cout << "TRUCK CLASS" << endl;
	cout << "The age of the car E is " << e.getAge() << "" << ". The car price is " << e.getPrice() << "" << ". The diesel status is " << e.getDieselTypeStatus()<< endl;
	Truck f;
	cout << "The age of the car F is " << f.getAge() << "" << ". The car price is " << f.getPrice() << "" << ". The race diesel status is " << f.getDieselTypeStatus() << endl;
	
	system("pause");
	return 0;
}