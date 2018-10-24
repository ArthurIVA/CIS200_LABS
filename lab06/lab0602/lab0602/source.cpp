//Program Name: FACTORIAL
//Programmer Name: Arthur Aigeltinger IV
//Description: Use recursion to perform the FACTORIAL !
//Date Created: 10/23/18

#include <iostream>

//Function Prototypes
int factorial(int input, bool &methodStatus);

int main()
{
	//Declare Variables
	bool methodStatus = false;
	int input = 0;

	std::cout << "Please enter an integer to find the factorial of: ";
	std::cin >> input;

	std::cout << input << "! = " << factorial(input, methodStatus) << std::endl;


	system("pause");
	return 0;
}

int factorial(int input, bool & methodStatus)
{
	methodStatus = true;

	if (input < 0)
	{
		methodStatus = false;
		return -1;
	}
	else if (input == 0)
	{
		return 1;
	}
	else
	{
		return (input * factorial(input - 1, methodStatus));
	}
}
