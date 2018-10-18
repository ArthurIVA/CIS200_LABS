#include <iostream>
#include "employee.h"


int main()
{
	employee test;

	//Test Default Constructor
	std::cout << "Testing Default Constructor" << std::endl;
	std::cout << "Default Age   : " << test.getAge() << std::endl;
	std::cout << "Default ID    : " << test.getID() << std::endl;
	std::cout << "Default Salary: " << test.getSalary() << std::endl;

	//Test Valid Employee Fill
	test.setAge(47);
	test.setID(777);
	test.setSalary(80880);

	std::cout << "Testing Valid Employee Data" << std::endl;
	std::cout << "New Age   : " << test.getAge() << std::endl;
	std::cout << "New ID    : " << test.getID() << std::endl;
	std::cout << "New Salary: " << test.getSalary() << std::endl;

	//Test Invalid Employee Fill
	test.setAge(-1);
	test.setID(-777);
	test.setSalary(-100000);

	system("pause");
	return 0;
}