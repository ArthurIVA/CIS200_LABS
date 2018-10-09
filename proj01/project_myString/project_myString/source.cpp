//Program Name: myString
//Programmer Name: Arthur Aigeltinger IV
//Description: A custom built version of the built in C++ "string" library.
//Date Created: 10/07/18

#include "myString.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

//Function Prototypes
void menu();
void printErrorCode(int);
void printLog(std::ofstream&, std::string, std::string, std::string, std::string, std::string, int);

int main()
{
	//Menu related variables
	int userChoice = 0;
	int error = 0;
	int startPos = 0;
	int length = 0;

	//String declared to interface with new myString class
	std::string holderString;
	std::string holderString2;
	std::string result;

	//Declare all output file related variables
	std::string fileName = "outputLog.txt";
	std::ofstream output;

	//Two seperate instances of myString to allow methods that include parameters or comparisons of type myString
	myString testString;
	myString testString2;

	menu();

	//Open Log File
	output.open(fileName);

	//Enter Decision Phase
	do
	{
		//Defaults
		holderString = "";
		holderString2 = "";
		result = "";
		testString.initString();
		testString2.initString();
		int error = 0;
		int startPos = 0;
		int length = 0;

		std::cout << std::endl << "Choice: ";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 0:
			//Close Output File
			output.close();
			return 0;
				break;
		case 1:
			std::cout << "Testing myString::size()" << std::endl;
			std::cout << "Fill String  : ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			//Process
			//Print Result
			std::cout << "Result       : ";
			std::cout << testString.size() << std::endl;

			result = std::to_string(testString.size());
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "size()", holderString, "NULL", "NULL", result, error);
			break;

		case 2:
			std::cout << "Testing myString::addStart(myString)" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "Fill String 2: ";
			//Take in as string::string
			std::cin >> holderString2;
			//Set as myString
			testString2.setString(holderString2);

			//Process
			testString.addStart(testString2);

			//Print Result
			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "addStart(myString)", holderString, holderString2, "NULL", result, error);
			break;

		case 3:
			std::cout << "Testing myString::addEnd(myString)" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "Fill String 2: ";
			//Take in as string::string
			std::cin >> holderString2;
			//Set as myString
			testString2.setString(holderString2);

			//Process
			testString.addEnd(testString2);

			//Print Result
			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "addEnd(myString)", holderString, holderString2, "NULL", result, error);
			break;

		case 4:
			std::cout << "Testing myString::partString(startPos, length)" << std::endl;
			std::cout << "Fill String  : ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "startPos     : ";
			std::cin >> startPos;

			std::cout << "length       : ";
			std::cin >> length;

			//Process
			testString.replWholeString(testString.partString(startPos, length));

			//Print Result
			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "partString(startPos, length)", holderString, std::to_string(startPos), std::to_string(length), result, error);
			break;

		case 5:
			std::cout << "Testing myString::replPartString(myString, startPos)" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "Fill String 2: ";
			//Take in as string::string
			std::cin >> holderString2;
			//Set as myString
			testString2.setString(holderString2);

			std::cout << "startPos     : ";
			std::cin >> startPos;

			//Process
			testString.replPartString(testString2, startPos);

			//Print Result
			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "replPartString(myString, startPos)", holderString, holderString2, std::to_string(startPos), result, error);
			break;

		case 6:
			std::cout << "Testing myString::replWholeString(myString)" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "Fill String 2: ";
			//Take in as string::string
			std::cin >> holderString2;
			//Set as myString
			testString2.setString(holderString2);

			//Process
			testString.replWholeString(testString2);

			//Print Result
			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "replWholeString(myString)", holderString, holderString2, "NULL", result, error);
			break;

		case 7:
			std::cout << "Testing myString::compareString(myString)" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "Fill String 2: ";
			//Take in as string::string
			std::cin >> holderString2;
			//Set as myString
			testString2.setString(holderString2);

			//Process
			//Print Result
			std::cout << "Result       : ";
			std::cout << (testString.compareString(testString2));

			result = testString.compareString(testString2);
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "compareString(myString)", holderString, holderString2, "NULL", result, error);
			break;

		case 8:
			std::cout << "Testing myString::initString()" << std::endl;
			std::cout << "Fill String  : ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			//Process
			testString.initString();

			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "initString()", holderString, "NULL", "NULL", result, error);
			break;

		case 9:
			std::cout << "Testing myString::setString(std::string)" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			//Processs
			testString.setString(holderString);

			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "setString(string)", holderString, holderString, "NULL", result, error);
			break;
				
		case 10:
			std::cout << "Testing myString::getString()" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			std::cout << "Result       : ";
			testString.printStringScreen();

			//Processs
			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "getString()", holderString, "NULL", "NULL", result, error);
			break;

		case 11:
			std::cout << "Testing myString::printStringScreen()" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			//Process
			std::cout << "Result       : ";
			testString.printStringScreen();

			result = testString.getString();
			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "printStringScreen()", holderString, "NULL", "NULL", result, error);
			break;

		case 12:
			std::cout << "Testing myString::numericString()" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			if (testString.numericString())
			{
				//Process
				std::cout << "Result       : ";
				std::cout << "Is a Real Number";
				result = "Is Real Number";
			}
			else
			{
				//Process
				std::cout << "Result       : ";
				std::cout << "Not a Real Number";
				result = "Not Real Number";
			}

			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "numericString()", holderString, "NULL", "NULL", result, error);
			break;

		case 13:
			std::cout << "Testing myString::alphabeticString()" << std::endl;
			std::cout << "Fill String 1: ";
			//Take in as string::string
			std::cin >> holderString;
			//Set as myString
			testString.setString(holderString);

			if (testString.alphabeticString())
			{
				//Process
				std::cout << "Result       : ";
				std::cout << "Is Alphabetic";
				result = "Is Alphabetic";
			}
			else
			{
				//Process
				std::cout << "Result       : ";
				std::cout << "Not Alphabetic";
				result = "Not Alphabetic";
			}

			error = testString.getErrorCode();

			printErrorCode(error);

			printLog(output, "alphabeticString()", holderString, "NULL", "NULL", result, error);
			break;

		case 14:
			menu();
			break;

			default:
				std::cout << "Invalid Choice, Try Again" << std::endl;
				break;
			}
		} 
	while (userChoice != 0);

	system("pause");
	return 0;
}


void menu()
{
	//Prompt
	std::cout << "Please select a function to test by entering it's number: ";
	std::cout << std::endl;
	std::cout << "Functions of myString								" << std::endl;
	std::cout << "(1)  size()										" << std::endl;
	std::cout << "(2)  addStart(myString)							" << std::endl;
	std::cout << "(3)  addEnd(myString)								" << std::endl;
	std::cout << "(4)  partString(startPos, length)					" << std::endl;
	std::cout << "(5)  replPartString(myString, startPos)			" << std::endl;
	std::cout << "(6)  replWholeString(myString)					" << std::endl;
	std::cout << "(7)  compareString(myString)						" << std::endl;
	std::cout << "(8)  initString()									" << std::endl;
	std::cout << "(9)  setString(string)							" << std::endl;
	std::cout << "(10) getString()									" << std::endl;
	std::cout << "(11) printStringScreen()							" << std::endl;
	std::cout << "(12) numericString()								" << std::endl;
	std::cout << "(13) alphabeticString()							" << std::endl;
	std::cout << std::endl;
	std::cout << "Other Function									" << std::endl;
	std::cout << "(14) menu() - Draw this menu again				" << std::endl;
	std::cout << "(0)  EXIT											" << std::endl;
}

void printErrorCode(int error)
{
	std::cout << std::endl;
	switch (abs(error))
	{
	case 0:
		std::cout << "Error Code   : 0  - No Errors Occured" << std::endl;
		break;
	case 1:
		std::cout << "Error Code   : -1  *Attempted to fill string with more than 25 character*" << std::endl;
		break;
	case 2:
		std::cout << "Error Code   : -2  *Attempted to access index above 25*" << std::endl;
		break;
	case 3:
		std::cout << "Error Code   : -3  *Attempted to fill with whitespace*" << std::endl;
		break;
	}
}

void printLog(std::ofstream& out, std::string function, std::string initialString, std::string paramOne, std::string paramTwo, std::string result, int error)
{
	out << "Function Tested : " << function << std::endl;
	out << "Initial String  : " << initialString << std::endl;
	out << "Parameter 1     : " << paramOne << std::endl;
	out << "Parameter 2     : " << paramTwo << std::endl;
	out << "Result          : " << result << std::endl;

	switch (abs(error))
	{
	case 0:
		out << "Error Code      : 0  - No Errors Occured" << std::endl;
		break;
	case 1:
		out << "Error Code      : -1  *Attempted to fill string with more than 25 character*" << std::endl;
		break;
	case 2:
		out << "Error Code      : -2  *Attempted to access index above 25*" << std::endl;
		break;
	case 3:
		out << "Error Code      : -3  *Attempted to fill with whitespace*" << std::endl;
		break;
	}
	out << std::endl;
}