#pragma once
#include "customer.h"

#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

class preferredCustomer : public customer
{
private:
	double purchasesAmount;
	int discountLevel; 

public:
	//Default Constructor
	preferredCustomer();

	//Setter Commands
	void setPurchaseAmount(double);
	void setDiscountLevel(int);
	
	//Getter Commands
	double getPurchaseAmount();
	int getDiscountLevel();

	//Member Functions
	void calculateDiscount();
	void printPreferredCustomer();

	//Default Destructor
	~preferredCustomer();
};

#endif