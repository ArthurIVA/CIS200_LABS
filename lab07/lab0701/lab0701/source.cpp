//Program Name: Client Data - RANDOM ACCESS
//Programmer Name: Arthur Aigeltinger IV
//Description: A toe dipped in the water of random file access that is still a little over my head but I'm glad I made it this far. Thanks for coming to my TedTalk...
//Date Created: 10/29/18

#include <fstream>
#include <iostream>
#include <ostream>

//Define Struct
struct clientData
{
	int accountNumber;
	char lastName[15];
	char firstName[10];
	float balance;
};

//Function Prototypes
void createBlankFile(clientData);
void writeToFile(clientData);
void userRead(clientData);
void printAllRecords(clientData);

int main()
{

	//Initialize Blank and Holder Client
	clientData blankClient = { 0,"","",0.0 };
	clientData client = { 0,"","",0.0 };

	createBlankFile(blankClient);
	writeToFile(client);
	userRead(client);
	printAllRecords(client);

	system("pause");
	return 0;
}

//Description: Creates and Initialized a "blank" file with the size and space to fit 100 instances of struct [clientData]
//Pre-Condition: We need a file
//Post-Condition: WE'VE GOT A FILE
void createBlankFile(clientData blankClient)
{
	//Create and Open Output Stream
	std::ofstream outCredit("credit.dat", std::ios::out);

	//Fill File with blankClient
	for (int i = 0; i < 100; i++)
	{
		outCredit.write(reinterpret_cast<const char *>(&blankClient), sizeof(clientData));
	}

	//Close File Stream
	outCredit.close();
}

//Description: Enters loop to ask user for client data to be pushed to the pre-generated file
//Pre-Condition: File is at its default, empty state
//Post-Condition: File is filled with individual user accounts as determined bu the user
void writeToFile(clientData client)
{
	//Open Client Output Stream	
	std::ofstream outCredit1("credit.dat", std::ios::ate);

	//Announce Function to User
	std::cout << std::endl;
	std::cout << "Inputting Specific User Data" << std::endl;
	std::cout << std::endl;

	do //Filling Client Data until accountNumber = 0
	{
		//Initial Prompt
		std::cout << std::endl;
		std::cout << "Please Enter an Account Number (1-100)" << std::endl;
		std::cout << "Entering 0 Will Exit User Input" << std::endl;
		std::cout << "Account Number: ";
		std::cin >> client.accountNumber;

		if (client.accountNumber == 0)
		{
			outCredit1.close(); //Close Output Stream
			return; //Exit Function
		}
		else if (client.accountNumber >= 1 && client.accountNumber <= 100)
		{
			//Fill In Order
			std::cout << "First Name: ";
			std::cin >> client.firstName;
			std::cout << "Last Name: ";
			std::cin >> client.lastName;
			do
			{
				std::cout << "Balance: ";
				std::cin >> client.balance;
			} while (client.balance < 0);

			outCredit1.seekp((client.accountNumber - 1) * sizeof(clientData));
			outCredit1.write(reinterpret_cast<const char*>(&client), sizeof(clientData));
		}
		else
		{
			std::cout << "Invalid Account Number" << std::endl;
		}
	} while (client.accountNumber != 0); //Checking to repeat even though case [0] is handled with initial "if"
}

//Description: Allows user to request specific client accounts and have them printed to the screen
//Pre-Condition: Filled client data file via writeToFile()
//Post-Condition: Client account(s) requested are printed to console
void userRead(clientData client)
{
	//Holder Variable
	int userIn = 0;

	//Open Input Stream
	std::ifstream inCredit("credit.dat", std::ios::in);

	//Announce Function to User
	std::cout << std::endl;
	std::cout << "Request Specific User Data" << std::endl;
	//std::cout << std::endl;

	do
	{
		std::cout << std::endl;
		std::cout << "Enter 0 To Exit" << std::endl;
		std::cout << "Enter Account Number: ";
		std::cin >> userIn;

		if (userIn == 0)
		{
			std::cout << "Exiting" << std::endl;
			inCredit.close(); //Close Input Stream
			return; //Exit Function
		}
		else if (userIn >= 1 && userIn <= 100)
		{
			inCredit.seekg((userIn - 1) * sizeof(clientData));
			inCredit.read(reinterpret_cast<char *>(&client), sizeof(clientData));

				if (client.accountNumber == userIn)
				{
					//Output In Order
					std::cout << "Account Number: ";
					std::cout << client.accountNumber << std::endl;
					std::cout << "First Name:     ";
					std::cout << client.firstName << std::endl;
					std::cout << "Last Name:      ";
					std::cout << client.lastName << std::endl;
					std::cout << "Balance:       $";
					std::cout << client.balance << std::endl;
				}
				else //Checking for Invalid Within Range
				{
					std::cout << "ACCOUNT NUMBER NOT IN USE" << std::endl;
					client.accountNumber = -1;
				}
		}
		else //Checking for Invalid Outside Range
		{
			std::cout << "ACCOUNT NUMBER OUT OF RANGE" << std::endl;
			client.accountNumber = -1;
		}
	} while (client.accountNumber != 0);  //Checking to repeat even though case [0] is handled with initial "if"
}

//Description: Prints all of the filled records within "credit.dat"
//Pre-Condition: A valid, filled "credit.dat" file
//Post-Condition: All filled client data is printed on the console
void printAllRecords(clientData client)
{
	//Open Input Stream
	std::ifstream inCredit("credit.dat", std::ios::in);

	//Announce Function to User
	std::cout << std::endl;
	std::cout << "Printing ALL RECORDS" << std::endl;
	std::cout << std::endl;

	inCredit.read(reinterpret_cast<char *>(&client), sizeof(clientData));
	
	while (inCredit && !inCredit.eof())
	{
		if (client.accountNumber != 0) //MAY CAUSE INFINITE LOOP (TRY 100?)
		{
			//Output In Order
			std::cout << "Account Number: ";
			std::cout << client.accountNumber << std::endl;
			std::cout << "First Name:     ";
			std::cout << client.firstName << std::endl;
			std::cout << "Last Name:      ";
			std::cout << client.lastName << std::endl;
			std::cout << "Balance:       $";
			std::cout << client.balance << std::endl << std::endl;
		}

		inCredit.read(reinterpret_cast<char *>(&client), sizeof(clientData));
	}

}