#include "preferredCustomer.h"

preferredCustomer::preferredCustomer()
{
	purchasesAmount = 0;
	discountLevel = 0;
}

void preferredCustomer::setPurchaseAmount(double input)
{
	purchasesAmount = input;
}

void preferredCustomer::setDiscountLevel(int input)
{
	discountLevel = input;
}

double preferredCustomer::getPurchaseAmount()
{
	return purchasesAmount;
}

int preferredCustomer::getDiscountLevel()
{
	return discountLevel;
}

void preferredCustomer::calculateDiscount()
{
	if (getPurchaseAmount() > 2000)
	{
		setDiscountLevel(10);
	}
	else if (getPurchaseAmount() > 1500)
	{
		setDiscountLevel(7);
	}
	else if (getPurchaseAmount() > 1000)
	{
		setDiscountLevel(6);
	}
	else if(getPurchaseAmount() > 500)
	{
		setDiscountLevel(5);
	}
}

void preferredCustomer::printPreferredCustomer()
{
	printCustomer();
	std::cout << std::endl;
	std::cout << "Preferred Customer Info" << std::endl;
	std::cout << std::endl;
	std::cout << "Purchase Amount: " << getPurchaseAmount() << std::endl;
	std::cout << "Discount Level : " << getDiscountLevel() << "%" << std::endl;
}

preferredCustomer::~preferredCustomer()
{
}
