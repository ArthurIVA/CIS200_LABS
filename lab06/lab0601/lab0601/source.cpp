//Program Name: Recursive Linear Search
//Programmer Name: Arthur Aigeltinger IV
//Description: Use recursion to create a linear searching function.
//Date Created: 10/23/18

#include <iostream>

//Global Variables
const int SIZE = 5000;

//Function Prototypes
int recursiveLinearSearch(int array[], int key, int size, bool &methodStatus);

int main()
{
	//Declare Variables
	bool methodStatus = false;
	int recursiveCalls = 0;
	int key = 0;

	//Declare Array
	int intArray[SIZE];
	
	//Fill Array
	for (int i = 0; i < SIZE; i++)
	{
		intArray[i] = i;
	}

	std::cout << "Please enter a 'key' or number to search for: ";
	std::cin >> key;

	recursiveCalls = recursiveLinearSearch(intArray, key, SIZE, methodStatus);

	if (methodStatus)
	{
		std::cout << "Found Key " << key << " after " << recursiveCalls << " recursive calls" << std::endl;
	}
	else
	{
		std::cout << "Key was not found" << std::endl;
	}

	system("pause");
	return 0;
}

//Description: Recursively performs a liner search within a given sorted array.
//Pre-Condition: Array being filled
//Post-Condition: User will be satisfied.
int recursiveLinearSearch(int array[], int key, int size, bool & methodStatus)
{
	size--;	//Decrement Size

	if (size < 0 || key < 0 || key > size)	//Checking for valid size and key from the start
	{ 
		return -1;
	}
	else if (array[size] == key)			//When key is found
	{
		methodStatus = true;
		return SIZE - size;
	}
	else									//Recursive Call
	{
		return recursiveLinearSearch(array, key, size, methodStatus);
	}

	return 0;
}
