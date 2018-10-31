#pragma once
#include <iostream>
#include <string>

#ifndef PERSON_H
#define PERSON_H

//Base Class
class person
{
private:
	std::string lastName;
	std::string firstName;
	std::string address;
	std::string city;
	std::string state;
	std::string zip;
	std::string phone;

public:
	//Default Constructor
	person();

	//Setter Commands
	void setLastName(std::string);
	void setFirstName(std::string);
	void setAddress(std::string);
	void setCity(std::string);
	void setState(std::string);
	void setZip(std::string);
	void setPhone(std::string);

	//Getter Commands
	std::string getLastName();
	std::string getFirstName();
	std::string getAddress();
	std::string getCity();
	std::string getState();
	std::string getZip();
	std::string getPhone();

	//Member Functions
	void printPerson();

	//Default Destructor
	~person();

};
#endif