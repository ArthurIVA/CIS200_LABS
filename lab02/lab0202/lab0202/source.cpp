//Program Name:
//Programmer Name: Arthur Aigeltinger IV
//Description:
//Date Created: 09/25/18

#include <iostream>

#define NUM_DEPTS 2
#define NUM_STORES 2
#define NUM_MONTHS 12

//Function Prototypes
void printMonthlySales();


int main()
{
	float storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] = 
	{
		1.1, 1.2, 1.3, 1.4,  1.5, 1.6, 1.7, 1.8,  1.9, 2.0, 2.1, 2.2,
		2.1, 2.2, 2.3, 2.4,  2.5, 2.6, 2.7, 2.8,  2.9, 3.0, 3.1, 3.2,
		3.1, 3.2, 3.3, 3.4,  3.5, 3.6, 3.7, 3.8,  3.9, 4.0, 4.1, 4.2,
		2.1, 2.2, 2.3, 2.4,  2.5, 2.6, 2.7, 2.8,  2.9, 3.0, 3.1, 3.1
	};

	return 0;
}

void printMonthlySales()
{

}
