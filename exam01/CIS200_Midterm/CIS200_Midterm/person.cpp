#include "person.h"

//Default Constructor
person::person()
{
	lastName = "xxxxxx";
	firstName = "xxxxxx";
	address = "xxxxxx";
	city = "xxxxxx";
	state = "xxxxxx";
	zip = "xxxxxx";
	phone = "xxxxxx";
}

void person::setLastName(std::string input)
{
	lastName = input;
}

void person::setFirstName(std::string input)
{
	firstName = input;
}

void person::setAddress(std::string input)
{
	address = input;
}

void person::setCity(std::string input)
{
	city = input;
}

void person::setState(std::string input)
{
	state = input;
}

void person::setZip(std::string input)
{
	zip = input;
}

void person::setPhone(std::string input)
{
	phone = input;
}

std::string person::getLastName()
{
	return lastName;
}

std::string person::getFirstName()
{
	return firstName;
}

std::string person::getAddress()
{
	return address;
}

std::string person::getCity()
{
	return city;
}

std::string person::getState()
{
	return state;
}

std::string person::getZip()
{
	return zip;
}

std::string person::getPhone()
{
	return phone;
}


///Member Functions

void person::printPerson()
{
	std::cout << "PERSONAL DATA" << std::endl << std::endl;
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name : " << getLastName() << std::endl;
	std::cout << "Address   : " << getAddress() << std::endl;
	std::cout << "City      : " << getCity() << std::endl;
	std::cout << "State     : " << getState() << std::endl;
	std::cout << "ZIP       : " << getZip() << std::endl;
	std::cout << "Phone #   : " << getPhone() << std::endl;
}

//Default Destructor
person::~person()
{
	
}
