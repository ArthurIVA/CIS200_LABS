#include <iostream>
#include "person.h"
#include "customer.h"
#include "preferredCustomer.h"

int main()
{
	//Create Instances Of Each Class
	preferredCustomer nabeel;
	preferredCustomer ben;
	customer caleb;
	person arthur;

	///NABEEL
	//Setting Nabeel Personal Info
	nabeel.setFirstName("Nabeel");
	nabeel.setLastName("Igottaquestion");
	nabeel.setAddress("4901 Evergreen");
	nabeel.setCity("Dearborn");
	nabeel.setState("MI");
	nabeel.setZip("48126");
	nabeel.setPhone("313-436-9145");

	//Setting Nabeel Customer Info
	nabeel.setCustomerNumber(1);
	nabeel.setMailingList(true);
	nabeel.setComments("Class Questioner");

	//Print Original Nabeel Data
	nabeel.printPreferredCustomer();

	//Update Preferred Purchase Amount
	nabeel.setPurchaseAmount(1011);
	nabeel.calculateDiscount();

	std::cout << "- - - - - - - - - - - - - - - - - - - - - " << std::endl;
	std::cout << "Updated Data" << std::endl;

	//Print Updated Data
	nabeel.printPreferredCustomer();

	std::cout << "------------------------------------------" << std::endl;

	///BEN
	//Setting Ben Personal Info
	ben.setFirstName("Ben");
	ben.setLastName("Symboltable");
	ben.setAddress("12903 Ehab");
	ben.setCity("Dearborn");
	ben.setState("MI");
	ben.setZip("48126");
	ben.setPhone("313-436-9145");

	//Setting Customer Info
	ben.setCustomerNumber(2);
	ben.setMailingList(false);
	ben.setComments("Address Genorator");

	//Setting Preferred Info
	ben.setPurchaseAmount(2010);
	ben.calculateDiscount();

	//Print Original Ben Data
	ben.printPreferredCustomer();

	std::cout << "------------------------------------------" << std::endl;

	///CALEB
	//Setting Caleb Personal Info
	caleb.setFirstName("Caleb");
	caleb.setLastName("Kool");
	caleb.setAddress("1313 Mariah Blvd");
	caleb.setCity("Dearborn Heights");
	caleb.setState("MI");
	caleb.setZip("48127");
	caleb.setPhone("313-836-9168");

	//Setting Customer Info
	caleb.setCustomerNumber(3);
	caleb.setMailingList(false);
	caleb.setComments("Class Answerer");

	//Print Original Caleb Data
	caleb.printCustomer();

	std::cout << "------------------------------------------" << std::endl;

	///Arthur
	//Setting Arthur Personal Info
	arthur.setFirstName("Arthur");
	arthur.setLastName("Aplus");
	arthur.setAddress("903 Brehm Ave");
	arthur.setCity("Asfia");
	arthur.setState("MI");
	arthur.setZip("48168");
	arthur.setPhone("313-486-9935");

	arthur.printPerson();

	system("pause");
	return 0;
}