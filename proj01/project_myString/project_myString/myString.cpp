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
std::string myString::getString()
{
	return charArray;
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

myString myString::replPartString(myString input, int startPos)
{
	//Declare Holders
	myString holderString;

	if (startPos > this->length)
	{
		setErrorCode(-3);
	}
	else if ((startPos + input.size()) > MAX_SIZE)
	{
		setErrorCode(-1);
	}
	else
	{
		//Fill Holder myString
		for (int i = 0; i < input.getLength(); i++)
		{
			holderString.charArray[i] = input.charArray[i];
		}
		int j = 0;
		for (int i = (startPos - 1); i < (length + startPos - 1); i++)
		{
			this->charArray[i] = holderString.charArray[j];
			j++;
		}
		this->setLength(startPos + input.size());
	}

	return myString();
}

myString myString::replWholeString(myString input)
{
	if (input.size() > MAX_SIZE)
	{
		setErrorCode(-1);
	}
	else
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			this->charArray[i] = input.charArray[i];
		}
		this->setLength(input.size());
	}

	return myString();
}

bool myString::compareString(myString input)
{
	int i = 0;
	do
	{
		if (this->charArray[i] != input.charArray[i])
		{
			return false;
		}
		i++;
	} while (i < MAX_SIZE);

	return true;
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

bool myString::alphabeticString()
{
	int i = 0;
	while (this->charArray[i] != '\0')
	{
		if (!(isalpha(this->charArray[i])))
		{
			return false;
		}
		i++;
	}
	return true;
}

myString::~myString()
{
}
