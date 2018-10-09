#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H

#include <cctype>
#include <iostream>
#include <string> //Included to allow use of base string class to fill myString since recreating that is way above my pay grade...

//ERROR CODE LOOKUP
// -1 = Attempted to fill string with more than 25 characters.
// -2 = Attempted to access index above 25

class myString
{
private:

	//Define Constant
	const int MAX_SIZE = 25;

	//Define Holder Variables
	int errorCode = 0;
	int length = 0;

	//Define Container for myString
	char charArray[25];



public:
	myString();

	//Set Functions
	void setString(std::string); //PIRMARY FUNCTION
	void setErrorCode(int);
	void setLength(int);

	//Get Functions
	myString getString();
	int getErrorCode();
	int getLength();


	int size();
	void addStart(myString);
	void addEnd(myString);

	myString partString(int, int);
	myString replPartString(myString, int);

	void initString();
	void printStringScreen();

	bool numericString();

	~myString();
};

#endif // !myString.h
