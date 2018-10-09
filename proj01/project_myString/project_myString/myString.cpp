#include "myString.h"


//Default Constructor
myString::myString()
{
	charArray[MAX_SIZE];
	this->initString();
}

//PUBLIC METHODS
///SET COMMANDS
void myString::setString(std::string input)
{
	if (input.size() > MAX_SIZE)
	{
		setErrorCode(-1);
	}
	else
	{
		//Update with valid length
		setLength(input.size());

		//Iterate and fill character array with holder string.
		for (int i = 0; i < input.size(); i++)
		{
			charArray[i] = input.at(i);
		}
	}
}

void myString::setErrorCode(int input)
{
	errorCode = input;
}

void myString::setLength(int input)
{
	length = input;
}
///GET COMMANDS
myString myString::getString()
{
	return myString();
}
int myString::getErrorCode()
{
	return errorCode;
}
int myString::getLength()
{
	return length;
}


int myString::size()
{
	return getLength();
}


void myString::addStart(myString input)
{
	//Declare Holder Variables
	myString holderString;
	int tempLength = this->size();
	int tempLength2 = input.size();

	if ((input.size() + this->size()) > MAX_SIZE)
	{
		setErrorCode(-1);
	}
	else
	{
		//Fill Holder myString
		for (int i = 0; i < length; i++)
		{
			holderString.charArray[i] = this->charArray[i];
		}
		//Wipe myString to fill with new input
		this->initString();

		//Iterate and fill with user input
		for (int i = 0; i < input.size(); i++)
		{
			this->charArray[i] = input.charArray[i];
		}
		//Iterate further and fill with holder input
		for (int i = input.size(); i < (input.size() + tempLength); i++)
		{
			charArray[i] = holderString.charArray[i - input.size()];
		}
		this->setLength(tempLength + tempLength2);
	}
}
void myString::addEnd(myString input)
{
	//Declare Holder Variables
	int tempLength = this->size();
	int tempLength2 = input.size();

	if ((input.size() + this->size()) > MAX_SIZE)
	{
		setErrorCode(-1);
	}
	else
	{
		//Append character arrays
		int i = tempLength;
		int j = 0;
		do {
			this->charArray[i] = input.charArray[j];
			i++;
			j++;
		} while (i < (tempLength + tempLength2));
		//Update length
		this->setLength(tempLength + tempLength2);
	}
}

myString myString::partString(int startPos, int length)
{
	//Declare Holder
	myString holderString;

	if (startPos > MAX_SIZE)
	{
		setErrorCode(-2);
	}
	else if ((startPos + length) > MAX_SIZE)
	{
		setErrorCode(-2);
	}
	else
	{
		int j = 0;
		//Fill Holder myString
		for (int i = (startPos - 1); i < (length + startPos - 1); i++)
		{
			holderString.charArray[j] = this->charArray[i];
			j++;
		}
		holderString.setLength(this->getLength());
	}

	return holderString;
}
//IN PROGRESS -------------------------------------------------------------------------------------------------------
myString myString::replPartString(myString input, int startPos)
{
	if (startPos > MAX_SIZE)
	{
		setErrorCode(-2);
	}
	else if ((startPos + input.size()) > MAX_SIZE)
	{
		setErrorCode(-1);
	}
	else
	{
		for (int i = (startPos - 1); i < (length + startPos - 1); i++)
		{
			//holderString.charArray[j] = this->charArray[i];
			//j++;
		}

	}

	return myString();
}


void myString::initString()
{
	//Revert size to empty
	this->setLength(0);

	//Iterate and fill will null characters
	for (int i = 0; i < MAX_SIZE; i++)
	{
		charArray[i] = '\0';
	}
}
void myString::printStringScreen()
{
	for (int i = 0; i < size(); i++)
	{
		std::cout << charArray[i];
	}
}

bool myString::numericString()
{
	//Cast character array into double.
	double holder = atof(charArray);
	
	//This solution works for every possible input except zero
	if (holder == 0) //Input was not a real number, or zero
	{
		return false;
	}
	else //Input was a real number
	{
		return true;
	}
}

myString::~myString()
{
}
