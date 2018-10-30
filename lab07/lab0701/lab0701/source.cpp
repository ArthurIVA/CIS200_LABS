//Program Name: 
//Programmer Name: Arthur Aigeltinger IV
//Description: 
//Date Created: 10/29/18

#include <fstream>
#include <iostream>
#include <ostream>

//Define Struct
struct clientData
{
	int accountNumber = 0;
	char lastName[15];
	char firstName[10];
	float balance = 0.0;
};


int main()
{
	//Create and Open Output Stream
	std::ofstream outCredit("credit.dat", std::ios::out);

	//Initialize Blank/Prototype Client
	clientData blankClient = { 0,"","",0.0 }; 

	//Fill File with blankClient
	for (int i = 0; i < 100; i++)
	{
		outCredit.write(reinterpret_cast<const char *>(&blankClient), sizeof(clientData));
	}

	//Close File Stream
	outCredit.close();

	//Initialize New Client
	clientData client;

	//Fill Client Data
	std::ofstream outCredit1("credit.dat", std::ios::ate);

	for (int i = 0; i < 2; i++)
	{


		std::cout << "Account Number: ";
		std::cin >> client.accountNumber;
		std::cout << "First Name: ";
		std::cin >> client.firstName;
		std::cout << "Last Name: ";
		std::cin >> client.lastName;
		std::cout << "Balance: ";
		std::cin >> client.balance;

		outCredit1.seekp((client.accountNumber - 1) * sizeof(clientData));
		outCredit1.write(reinterpret_cast<const char*>(&client), sizeof(clientData));


	}
	
	outCredit1.close();

	//Print Records
	std::ifstream inCredit("credit.dat", std::ios::in);

	inCredit.read(reinterpret_cast<char *>(&client), sizeof(clientData));
	
	while (inCredit && !inCredit.eof())
	{
		if (client.accountNumber != 0)
		{
			std::cout << "found";
		}
	}

	system("pause");
	return 0;
}