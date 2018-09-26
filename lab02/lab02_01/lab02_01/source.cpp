//Program Name: 
//Programmer Name: Arthur Aigeltinger IV
//Description:
//Date Created: 09/25/18

#include <cctype>
#include <iostream>
#include <iomanip>

#define MAX_ROWS 3
#define MAX_COULMNS 2

//Function Prototypes
int howManyEven(int[][MAX_COULMNS]);
void printArray(int[][MAX_COULMNS]);


int main()
{
	//Initialize default array contents and 
	int arrayIntValues[MAX_ROWS][MAX_COULMNS] = { {3,2}, {4,5}, {2,2} };
	int userIn = 0; //NO LONGER NECESSARY
	char userChoice = ' ';

	std::cout << "This is the default example of a two-dimensional array." << std::endl;
	printArray(arrayIntValues);

	std::cout << "The number of even integers in this array is " << howManyEven(arrayIntValues) << std::endl << std::endl;

	std::cout << "Now it's your turn!" << std::endl;
	std::cout << "Please enter your own positive integers into the array," << std::endl;
	std::cout << "Press ENTER / RETURN after each integer." << std::endl;
	//Begin menu for user input
	do 
	{
		userChoice = ' ';

		//Outer loop iterates through rows with formatting.
		for (int i = 0; i < MAX_ROWS; i++)
		{
			//Inner Loop iterates through sub-columns of array.
			for (int j = 0; j < MAX_COULMNS; j++)
			{
				do
				{
					userIn = 0;
					std::cin >> userIn;
				} while (userIn <= 0);
				
				arrayIntValues[i][j] = userIn;
			}
		}

		std::cout << "This is your new array!" << std::endl;
		printArray(arrayIntValues);
		std::cout << "The number of even integers in this array is " << howManyEven(arrayIntValues) << std::endl << std::endl;

		std::cout << "Would you like to insert new positive integers? (y)es/(n)o?" << std::endl;
		std::cin >> userChoice;
	} while (userChoice != 'n');
	

	system("pause");
	return 0;
}


//Description: Identifies even integers within a 2 dimensional array and counts how many exist.
//Pre-Condition: 
//Post-Condition: 
int howManyEven(int arrayIntValues[][MAX_COULMNS])
{
	int numEvens = 0;

	//Outer loop iterates through rows with formatting.
	for (int i = 0; i < MAX_ROWS; i++)
	{
		//Inner Loop iterates through sub-columns of array.
		for (int j = 0; j < MAX_COULMNS; j++)
		{
			if ((arrayIntValues[i][j] % 2) == 0)
			{
				numEvens++;
			}
		}
	}
	return numEvens;
}

//Description: Iterates through two dimensional array and prints it in a formatted state.
//Pre-Condition: 
//Post-Condition: 
void printArray(int arrayIntValues[][MAX_COULMNS])
{
	std::cout << std::endl;
	//Outer loop iterates through rows with formatting.
	for (int i = 0; i < MAX_ROWS; i++)
	{
		//Formatting
		std::cout << std::setw(4) << std::left;

		//Inner Loop iterates through sub-columns of array.
		for (int j = 0; j < MAX_COULMNS; j++)
		{
			std::cout << " " << arrayIntValues[i][j];
		}
		//Drop to next row.
		std::cout << std::endl;
	}
	std::cout << std::endl;
}