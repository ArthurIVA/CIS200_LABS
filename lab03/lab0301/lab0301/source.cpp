//Program Name: Square Root Calculator
//Programmer Name: Arthur Aigeltinger IV
//Description: Use series approximation to calculate the square root.
//Date Created: 10/03/18


#include <assert.h>
#include <cctype>
#include <iostream>

//Function Prototype
double squareRoot(double);

int main()
{
	//Initialize Variables
	double userIn = 0;
	char userChoice = 'y';

	do
	{
		//Default Choice
		userChoice = 'y';

		//Prompt
		std::cout << "Please insert a number to find the root of: ";
		std::cin >> userIn;

		std::cout << "Sqare root is " << squareRoot(userIn) << "!" << std::endl << std::endl;

		do
		{
			//Prompt
			std::cout << "Would you like to calculate another? (y)es/(n)o?" << std::endl;
			std::cin >> userChoice;
			userChoice = std::tolower(userChoice);

		} while (!(userChoice == 'y' || userChoice == 'n'));

	} while (!(userChoice == 'n'));

	system("pause");
	return 0;
}

//Description: Function that will take in a double and return either a valid output, or
//Pre-condition: Having input that is valid to input.
//Post-Condition: Either an assertion or a valid square root.
double squareRoot(double x) 
{
	assert(x >= 0);

	if (x == 0)
	{
		return 0;
	}

	double xN = x / 2;
	double xNp1 = (xN + x / xN) / 2;

	while (abs(xN - xNp1) > 0.0001) //Absolute value to account for values that drop below 0
	{
		xN = xNp1;
		xNp1 = (xN + x / xN) / 2;
	}

	return xNp1;
}
