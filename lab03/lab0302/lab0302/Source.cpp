//Program Name: Square Root Calculator
//Programmer Name: Arthur Aigeltinger IV
//Description: Use series approinputimation to calculate the square root.
//Date Created: 10/03/18

#include "assert.h"
#include <iostream>
#include <fstream>
#include <string>

//Function Prototypes
void readIntFile(std::ifstream&, int intArray[], int &);
void printFileValues(int intArray[], int& length);

int main()
{
	//Declare Variables
	const int SIZE = 20;
	int length = 0;
	int intArray[SIZE];
	std::ifstream input;
	std::string fileName = "";

	//Prompt User
	std::cout << "Please enter the name of the file containing integers" << std::endl << "Default is [in.dat]: ";
	std::cin >> fileName;

	//Convert filename string to actual file
	input.open(fileName);

	//Check if file exists
	if (input.is_open())
	{
		readIntFile(input, intArray, length);
		std::cout << "WOOP" << std::endl;
		printFileValues(intArray, length);
	}
	else
	{
		std::cout << "Input file does not exist!" << std::endl;
	}

	system("pause");
	return 0;
}

//Description: Take in a user specified file and fill an array passed by reference.
//Pre-Condition: File being open, array existing.
//Post-Condition: Filled array!
void readIntFile(std::ifstream &input, int intArray[], int &length)
{
	int i = 0;

	while (!input.eof())
	{
		input >> intArray[i];
		i++;
	}
	length = i;
}

//Description: Prints the values in order of a given array from a file.
//Pre-Condition: Array being filled
//Post-Condition: User will be satisfied.
void printFileValues(int intArray[], int & length)
{
	assert(length > 0);

	std::cout << "Final length of array is " << length << std::endl;

	for (int i = 0; i < length; i++)
	{
		//Formatting
		std::cout << "Integer #" << i + 1 << ": " << intArray[i] << std::endl;
	}
}