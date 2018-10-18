//Car Individual Definition and Test
#include <iostream>
#include "car.h"

int main()
{
	car mustang;
	
	//Testing Valid
	std::cout << mustang.getRaceCarStatus() << std::endl;
	mustang.setRaceCarStatus(true);
	std::cout << mustang.getRaceCarStatus() << std::endl;

	system("pause");
	return 0;
}