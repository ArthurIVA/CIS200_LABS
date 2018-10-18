//Vehice + Car + Truck Definition and Test
#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "truck.h"

int main()
{
	car mustang;
	truck ranger;

	//Testing Car Defaults
	std::cout << "Testing Default Constructor for Mustang" << std::endl;
	std::cout << mustang.getAge() << std::endl;
	std::cout << mustang.getPrice() << std::endl;
	std::cout << mustang.getRaceCarStatus() << std::endl;
	
	//Testing Car Valid
	std::cout << "Testing Valid Data for Mustang" << std::endl;
	mustang.setAge(31);
	std::cout << mustang.getAge() << std::endl;
	mustang.setPrice(12345.7);
	std::cout << mustang.getPrice() << std::endl;
	mustang.setRaceCarStatus(true);
	std::cout << mustang.getRaceCarStatus() << std::endl;

	//Testing Car Invalid
	std::cout << "Testing Invalid Data for Mustang" << std::endl;
	mustang.setAge(-1);
	mustang.setPrice(-1);

	std::cout << std::endl;

	//Testing Truck Defaults
	std::cout << "Testing Default Constructor for Ranger" << std::endl;
	std::cout << ranger.getAge() << std::endl;
	std::cout << ranger.getPrice() << std::endl;
	std::cout << ranger.getDieselTypeStatus() << std::endl;

	//Testing Truck Valid
	std::cout << "Testing Valid Data for Ranger" << std::endl;
	ranger.setAge(18);
	std::cout << ranger.getAge() << std::endl;
	ranger.setPrice(8325.04);
	std::cout << ranger.getPrice() << std::endl;
	ranger.setDieselTypeStatus(true);
	std::cout << ranger.getDieselTypeStatus() << std::endl;

	//Testing Truck Invalid
	std::cout << "Testing Invalid Data for Ranger" << std::endl;
	ranger.setAge(-1);
	ranger.setPrice(-1);


	system("pause");
	return 0;
}