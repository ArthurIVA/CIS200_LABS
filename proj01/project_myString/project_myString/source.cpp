//Program Name: myString
//Programmer Name: Arthur Aigeltinger IV
//Description: A custom built version of the built in C++ "string" library.
//Date Created: 10/07/18

#include "myString.h"
#include <iostream>
#include <string>


int main()
{
	std::string holderString;

	myString testString;
	myString testString2;

	std::cout << "Fill String 1: ";
	std::cin >> holderString;
	testString.setString(holderString);

	std::cout << "Fill String 2: ";
	std::cin >> holderString;
	testString2.setString(holderString);

	testString.addEnd(testString2);
	testString.numericString();

	testString.printStringScreen();
	std::cout << std::endl;

	system("pause");
	return 0;
}