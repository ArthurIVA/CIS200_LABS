#include "customer.h"

customer::customer()
{
	customerNumber = 0;
	mailingList = false;
	comments = "xxxxxx";
}

void customer::setCustomerNumber(int input)
{
	customerNumber = input;
}

void customer::setMailingList(bool input)
{
	mailingList = input;
}

void customer::setComments(std::string input)
{
	comments = input;
}

int customer::getCustomerNumber()
{
	return customerNumber;
}

bool customer::getMailingList()
{
	return mailingList;
}

std::string customer::getComments()
{
	return comments;
}

void customer::printCustomer()
{
	std::string mailAns = "";

	if (getMailingList())
	{
		mailAns = "Yes";
	}
	else
	{
		mailAns = "No";
	}

	printPerson();
	std::cout << std::endl;
	std::cout << "Customer Info" << std::endl;
	std::cout << std::endl;
	std::cout << "Customer #:" << getCustomerNumber() << std::endl;
	std::cout << "Mailing?  :" << mailAns << std::endl;
	std::cout << "Comments  :" << getComments() << std::endl;

}

customer::~customer()
{
}
