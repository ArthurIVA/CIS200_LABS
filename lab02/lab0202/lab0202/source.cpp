//Program Name: Monthly Sales Calculator
//Programmer Name: Arthur Aigeltinger IV
//Description: Parses three dimensional array of sales data and computes totals for given departments, stores, and totals. Then writes this data to a formatted table.
//Date Created: 09/25/18

#include <cctype>
#include <iomanip>
#include <iostream>

#define NUM_DEPTS 2
#define NUM_STORES 2
#define NUM_MONTHS 12

//Function Prototypes
void printMonthlySales(float[][NUM_STORES][NUM_MONTHS], int);


int main()
{
	//Initialize default array
	float storeMonthlySales[NUM_DEPTS][NUM_STORES][NUM_MONTHS] =
	{
		1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2,
		2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2,
		3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2,
		2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2
	};
	//Define and Initialize userChoice
	int userMonth = 0;
	char userChoice = ' ';

	do
	{
		//Choose month
		do 
		{
			std::cout << "Please Select Month to View (1-12) : ";
			std::cin >> userMonth;
		} while (userMonth < 1 || userMonth > 12);

		//Run function while altering user choice month to base zero index.
		printMonthlySales(storeMonthlySales, userMonth - 1);
		
		//Choose to continue or not
		do
		{ 
			std::cout << "Would you like to view another month? (y)es/(n)o?" << std::endl;
			std::cin >> userChoice;
			userChoice = std::tolower(userChoice);
		} while (!(userChoice == 'y' || userChoice == 'n'));

	} while (userChoice != 'n');

	system("pause");
	return 0;
}

//Description: Identifies even integers within a 2 dimensional array and counts how many exist.
//Pre-Condition: Having array filled with sales data for each given department, store, and month.
//Post-Condition: n/a
void printMonthlySales(float storeMonthlySales[][NUM_STORES][NUM_MONTHS], int userMonth)
{
	//Calculate row and column additions on the fly
	float rowOne = storeMonthlySales[0][0][userMonth] + storeMonthlySales[1][0][userMonth];
	float rowTwo = storeMonthlySales[0][1][userMonth] + storeMonthlySales[1][1][userMonth];
	float colOne = storeMonthlySales[0][0][userMonth] + storeMonthlySales[0][1][userMonth];
	float colTwo = storeMonthlySales[1][0][userMonth] + storeMonthlySales[1][1][userMonth];
	float totalOverall = storeMonthlySales[0][0][userMonth] + storeMonthlySales[0][1][userMonth] + storeMonthlySales[1][0][userMonth] + storeMonthlySales[1][1][userMonth];

	//Formatting and printing table with values.
	std::cout << "            " << "Dept #1 " << "Dept #2 " << "Store Total" << std::endl;
	std::cout << "Store #1    " << std::setw(8) << std::left << storeMonthlySales[0][0][userMonth] << std::setw(8) << std::left << storeMonthlySales[1][0][userMonth] << rowOne << std::endl;
	std::cout << "Store #2    " << std::setw(8) << std::left << storeMonthlySales[0][1][userMonth] << std::setw(8) << std::left << storeMonthlySales[1][1][userMonth] << rowTwo << std::endl;
	std::cout << "Dept Total  " << std::setw(8) << std::left << colOne << std::setw(8) << std::left << colTwo << totalOverall << std::endl;
}
