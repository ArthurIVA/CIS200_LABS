#pragma once
#include "person.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class customer : public person
{
private:
	int customerNumber;
	bool mailingList;
	std::string comments;


public:
	//Default Constructor
	customer();

	//Setter Commands
	void setCustomerNumber(int);
	void setMailingList(bool);
	void setComments(std::string);

	//Getter Commands
	int getCustomerNumber();
	bool getMailingList();
	std::string getComments();

	//Member Functions
	void printCustomer();

	//Default Destructor
	~customer();
};
#endif