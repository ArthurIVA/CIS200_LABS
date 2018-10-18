#include <iomanip>
#include <iostream>
#include "employee.h"

const int MAX_ROWS = 2;
const int MAX_COLS = 3;

//Function Prototypes
void printEmployee(employee[MAX_ROWS][MAX_COLS], int, int);

int main()
{
	//Create 2 dim array of employees
	employee x[MAX_ROWS][MAX_COLS];

	//Set Ages
	x[0][0].setAge(30);
	x[0][1].setAge(31);
	x[0][2].setAge(32);
	x[1][0].setAge(33);
	x[1][1].setAge(34);
	x[1][2].setAge(35);

	//Set IDs
	x[0][0].setID(111);
	x[0][1].setID(112);
	x[0][2].setID(113);
	x[1][0].setID(114);
	x[1][1].setID(115);
	x[1][2].setID(116);

	//Set Salaries
	x[0][0].setSalary(30000);
	x[0][1].setSalary(31000);
	x[0][2].setSalary(32000);
	x[1][0].setSalary(33000);
	x[1][1].setSalary(34000);
	x[1][2].setSalary(35000);

	printEmployee(x, MAX_ROWS, MAX_COLS);

	system("pause");
	return 0;
}

//Description: Print out two dimensional array of employeee data.
//Pre-Condition: An array with employee age, ID, and salary
//Post-Condition: Printed!
void printEmployee(employee x[MAX_ROWS][MAX_COLS], int, int)
{
	//Counter
	int employCount = 0;

	//Totals
	int totalAge = 0;
	float totalSalary = 0;
	
	//Averages
	double averageAge = 0.0;
	float averageSalary = 0.0;


	//Table Header with columns
	std::cout << std::setw(10) << std::left << "Employee" << std::setw(8) << "Age" << std::setw(8) << "ID" << std::setw(8) << "Salary" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	for  (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			//Iterate Employee
			employCount++;
			//Print Formatted Data
			std::cout << std::setw(10) << std::left << employCount << std::setw(8) << x[i][j].getAge() << std::setw(8) << x[i][j].getID() << std::setw(8) << x[i][j].getSalary() << std::endl;
			//Compund Age
			totalAge += x[i][j].getAge();
			//Compund Salary
			totalSalary += x[i][j].getSalary();
		}
	}
	
	//Calculate Averages
	averageAge = totalAge / (double)employCount;
	averageSalary = totalSalary / (float)employCount;

	std::cout << "--------------------------------" << std::endl;
	std::cout << std::setw(10) << "Averages" << std::setw(8) << std::left << averageAge << std::setw(8) << "" << std::setw(8) << averageSalary << std::endl;

}
