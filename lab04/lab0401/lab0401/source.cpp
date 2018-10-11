#include "vector.h"
#include <iostream>

int main()
{
	//REQUIRED CODE

	Vector a, b(3), c(3);

	std::cout << "Valid Test Case 1       : ";
	a.print();		//outputs []
	std::cout << "Valid Test Case 2       : ";
	b.print();		//outputs [ 0 0 0 ]
	std::cout << "Invalid Test Case 1     : ";
	c.set(0, -1);	//outputs error message
	c.set(1, 0);
	c.set(2, 1);
	c.set(3, 2);
	std::cout << "Invalid Test Case 2     : ";
	c.set(4, 3);	//outputs error message
	std::cout << "Valid Test Cases 3, 4, 5: ";
	c.print();		//outputs [ 1 2 3 ]

	Vector d(c);
	std::cout << "Valid Test Case 6       : ";
	d.print();		//outputs [ 1 2 3 ]

	d.set(0, 1);
	std::cout << "Valid Test Case 7       : ";
	d.print();		//outputs [ 1 0 3 ]
	std::cout << "Valid Test Case 8       : ";
	c.print();		//outputs [ 1 2 3 ] proves deep copy

	//ADDITIONAL TEST CASES
	std::cout << "Valid Test Case 9       : ";
	Vector e(a);
	e.print();
	std::cout << "Invalid Test Case 3     : ";
	Vector f(-1);

	system("pause");

	return 0;
}