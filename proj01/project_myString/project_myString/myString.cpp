#include "myString.h"

//Default Constructor
myString::myString()
{
	charArray[MAX_SIZE];
	this->initString();
}

//PUBLIC METHODS
///SET COMMANDS

//Description: Sets character array in myString equal to string input
//Pre-Condition: string <= 25 character w/o whitespace
//Post-Condition: Filled character array in myString
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

//Description: Access and update private variable errorCode. See list in Header File
//Pre-Condition: An error code needs updating
//Post-Condition: An error code gets updated
void myString::setErrorCode(int input)
{
	errorCode = input;
}

//Description: Access and update private variable length
//Pre-Condition: Need to keep track of length of character array/myString as it is changed
//Post-Condition: length that accuratly matched character array in myString
void myString::setLength(int input)
{
	length = input;
}

///GET COMMANDS

//Description: Retrieve character array and present it in a way that can be shown to the user or used in output log.
//Pre-Condition: NEED MYSTRING
//Post-Condition: YOU GOT MYSTRING
std::string myString::getString()
{
	return charArray;
}

//Description: Retrieve error code for use in output log	
//Pre-Condition: Error code needed for output.
//Post-Condition: YOU GOT IT
int myString::getErrorCode()
{
	return errorCode;
}

//Description:  Retrieve private variable length
//Pre-Condition: need
//Post-Condition: got
int myString::getLength()
{
	return length;
}

//Description: Forward the current size of character array
//Pre-Condition: need size
//Post-Condition: YOU GOT IT BOSS
int myString::size()
{
	return getLength();
}

//Description: Appends secondary input to the beginning of original myString
//Pre-Condition: An original myString and an addition
//Post-Condition: addition at the beginning of myString
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

//Description: Appends secondary string to the end of a primary string
//Pre-Condition: An original myString an extra myString
//Post-Condition: Lo and behold they are mended together...
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

//Description: Returns portion of myString from given starting position and length
//Pre-Condition: A string, A spot, and A distance.
//Post-Condition: "He's going the distance"
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

//Description: Replaces portion of myString with secondary myString beginning at a given position
//Pre-Condition: myString to insert, and a position.
//Post-Condition: lime in the coconut.
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

//Description: Replaces current myString with entirely new myString
//Pre-Condition: bloodlust to kill current myString.
//Post-Condition: Zero evidence it ever happened outside of your mind.
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

//Description: Check to see if two given myStrings are identical.
//Pre-Condition: 2 myStrings
//Post-Condition: true or false
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

//Description: Initializes myString will null characters
//Pre-Condition: desire to erase
//Post-Condition: ... theres nothing here ...
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

//Description: Does what it says
//Pre-Condition: Does it really matter?
//Post-Condition: Does anything really matter?
void myString::printStringScreen()
{
	for (int i = 0; i < size(); i++)
	{
		std::cout << charArray[i];
	}
}

//Description: Casts character array into double.
//Pre-Condition: If character array contains any non-real int chars, it evaluates to zero
//Post-Condition: this is a flawed approach as it means you cant perform this function on a real zero. Didn't have time to build a regular expression from scratch.
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

//Description: Iterate and see if char array contains any non alpha chars
//Pre-Condition: a char array
//Post-Condition: a yes or no answer
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

//Default Detructor
myString::~myString()
{
}
