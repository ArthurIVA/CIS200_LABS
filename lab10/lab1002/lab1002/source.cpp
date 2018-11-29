//Program Name: MEGA CONSTRUCTOR 
//Programmer Name: Arthur Aigeltinger IV
//Description: Use Template Classes with copy constructors to do STUFF!
//Date Created:	11/28/2018

#include <iostream>
#include <fstream>
#include <string>

//Date Structure
struct Date
{
	int month;
	int day;
	int year;
};

//Class Definitions
template <typename T>
class A 
{
protected:
	T valueA;

	A(A &temp) 
	{
		valueA = temp.getValueA();
	}

	A(T a) 
	{
		valueA = a;
	}

public:
	void setvalueA(T data) 
	{
		valueA = data;
	}

	T getValueA() 
	{
		return valueA;
	}
};

template <typename T>
class B : public A<T> 
{
protected:
	T valueB;
public:
	B(B &temp) : A<T>(temp) 
	{

		valueB = temp.getValueB();
	}

	B(T a, T b) : A<T>(a) 
	{
		valueB = b;
	}

	void setvalueB(T data) 
	{
		valueB = data;
	}

	T getValueB() 
	{
		return valueB;
	}
};


int main() 
{

	//Declare and Open Output File Stream
	std::ofstream output("out.txt");

	///FLOAT-------------------------------------------------------------------------------------

	//Testing Float Constructor
	B<float> floatTest(1.34, 3.14);
	
	//Console Output
	std::cout << "Float Testing" << std::endl;
	std::cout << "Value A: " << floatTest.getValueA() << std::endl;
	std::cout << "Value B: " << floatTest.getValueB() << std::endl;
	//File Output
	output << "Float Testing" << std::endl;
	output << "Value A: " << floatTest.getValueA() << std::endl;
	output << "Value B: " << floatTest.getValueB() << std::endl;

	//Testing Float Copy Constructor
	B<float> copyFloatTest(floatTest);

	//Console Output
	std::cout << "Float Copy Testing" << std::endl;
	std::cout << "Value A: " << copyFloatTest.getValueA() << std::endl;
	std::cout << "Value B: " << copyFloatTest.getValueB() << std::endl;
	//File Output
	output << "Float Copy Testing" << std::endl;
	output << "Value A: " << copyFloatTest.getValueA() << std::endl;
	output << "Value B: " << copyFloatTest.getValueB() << std::endl;

	//Testing Changing Values
	floatTest.setvalueA(6.28);
	floatTest.setvalueB(66.666);

	//Console Output
	std::cout << "Changing Float Values" << std::endl;
	std::cout << "Value A: " << floatTest.getValueA() << std::endl;
	std::cout << "Value B: " << floatTest.getValueB() << std::endl;
	//File Output
	output << "Changing Float Values" << std::endl;
	output << "Value A: " << floatTest.getValueA() << std::endl;
	output << "Value B: " << floatTest.getValueB() << std::endl;

	//Formatting
	std::cout << std::endl;

	///INTEGER-------------------------------------------------------------------------------------

	//Testing Integer Constructor
	B<int> integerTest(1, 3);

	//Console Output
	std::cout << "Integer Testing" << std::endl;
	std::cout << "Value A: " << integerTest.getValueA() << std::endl;
	std::cout << "Value B: " << integerTest.getValueB() << std::endl;
	//File Output
	output << "Integer Testing" << std::endl;
	output << "Value A: " << integerTest.getValueA() << std::endl;
	output << "Value B: " << integerTest.getValueB() << std::endl;

	//Testing Integer Copy Constructor
	B<int> copyIntegerTest(integerTest);

	//Console Output
	std::cout << "Integer Copy Testing" << std::endl;
	std::cout << "Value A: " << copyIntegerTest.getValueA() << std::endl;
	std::cout << "Value B: " << copyIntegerTest.getValueB() << std::endl;
	//File Output
	output << "Integer Copy Testing" << std::endl;
	output << "Value A: " << copyIntegerTest.getValueA() << std::endl;
	output << "Value B: " << copyIntegerTest.getValueB() << std::endl;

	//Testing Changing Values
	integerTest.setvalueA(777);
	integerTest.setvalueB(76);

	//Console Output
	std::cout << "Changing Integer Values" << std::endl;
	std::cout << "Value A: " << integerTest.getValueA() << std::endl;
	std::cout << "Value B: " << integerTest.getValueB() << std::endl;
	//File Output
	output << "Changing Integer Values" << std::endl;
	output << "Value A: " << integerTest.getValueA() << std::endl;
	output << "Value B: " << integerTest.getValueB() << std::endl;

	//Formatting
	std::cout << std::endl;

	///CHARACTER-------------------------------------------------------------------------------------

	//Testing Character Constructor
	B<char> characterTest('a', 'c');

	//Console Output
	std::cout << "Character Testing" << std::endl;
	std::cout << "Value A: " << characterTest.getValueA() << std::endl;
	std::cout << "Value B: " << characterTest.getValueB() << std::endl;
	//File Output
	output << "Character Testing" << std::endl;
	output << "Value A: " << characterTest.getValueA() << std::endl;
	output << "Value B: " << characterTest.getValueB() << std::endl;

	//Testing Character Copy Constructor
	B<char> copyCharacterTest(characterTest);

	//Console Output
	std::cout << "Character Copy Testing" << std::endl;
	std::cout << "Value A: " << copyCharacterTest.getValueA() << std::endl;
	std::cout << "Value B: " << copyCharacterTest.getValueB() << std::endl;
	//File Output
	output << "Character Copy Testing" << std::endl;
	output << "Value A: " << copyCharacterTest.getValueA() << std::endl;
	output << "Value B: " << copyCharacterTest.getValueB() << std::endl;

	//Testing Changing Values
	characterTest.setvalueA('f');
	characterTest.setvalueB('u');

	//Console Output
	std::cout << "Changing Character Values" << std::endl;
	std::cout << "Value A: " << characterTest.getValueA() << std::endl;
	std::cout << "Value B: " << characterTest.getValueB() << std::endl;
	//File Output 
	output << "Changing Character Values" << std::endl;
	output << "Value A: " << characterTest.getValueA() << std::endl;
	output << "Value B: " << characterTest.getValueB() << std::endl;

	//Formatting
	std::cout << std::endl;

	///STRING-------------------------------------------------------------------------------------

	//Testing String Constructor
	B<std::string> stringTest("good", "morning");

	//Console Output
	std::cout << "String Testing" << std::endl;
	std::cout << "Value A: " << stringTest.getValueA() << std::endl;
	std::cout << "Value B: " << stringTest.getValueB() << std::endl;
	//File Output
	output << "String Testing" << std::endl;
	output << "Value A: " << stringTest.getValueA() << std::endl;
	output << "Value B: " << stringTest.getValueB() << std::endl;

	//Testing String Copy Constructor
	B<std::string> copyStringTest(stringTest);

	//Console Output
	std::cout << "String Copy Testing" << std::endl;
	std::cout << "Value A: " << copyStringTest.getValueA() << std::endl;
	std::cout << "Value B: " << copyStringTest.getValueB() << std::endl;
	//File Output 
	output << "String Copy Testing" << std::endl;
	output << "Value A: " << copyStringTest.getValueA() << std::endl;
	output << "Value B: " << copyStringTest.getValueB() << std::endl;

	//Testing Changing Values
	stringTest.setvalueA("great");
	stringTest.setvalueB("grade");

	//Console Output
	std::cout << "Changing String Values" << std::endl;
	std::cout << "Value A: " << stringTest.getValueA() << std::endl;
	std::cout << "Value B: " << stringTest.getValueB() << std::endl;
	//File Output
	output << "Changing Sring Values" << std::endl;
	output << "Value A: " << stringTest.getValueA() << std::endl;
	output << "Value B: " << stringTest.getValueB() << std::endl;

	//Formattting
	std::cout << std::endl;

	///DATE-------------------------------------------------------------------------------------

	//Testing Date Constructor
	B<Date> dateTest({ 10,27,2015 }, { 11,2,2015 });

	//Console Output
	std::cout << "Date Testing" << std::endl;
	std::cout << "Value A: " << dateTest.getValueA().month << "/" << dateTest.getValueA().day << "/" << dateTest.getValueA().year << std::endl;
	std::cout << "Value B: " << dateTest.getValueB().month << "/" << dateTest.getValueB().day << "/" << dateTest.getValueB().year << std::endl;
	//File Output
	output << "Date Testing" << std::endl;
	output << "Value A: " << dateTest.getValueA().month << "/" << dateTest.getValueA().day << "/" << dateTest.getValueA().year << std::endl;
	output << "Value B: " << dateTest.getValueB().month << "/" << dateTest.getValueB().day << "/" << dateTest.getValueB().year << std::endl;

	//Testing Date Copy Constructor
	B<Date> copyDateTest(dateTest);

	//Console Output
	std::cout << "Date Copy Testing" << std::endl;
	std::cout << "Value A: " << copyDateTest.getValueA().month << "/" << copyDateTest.getValueA().day << "/" << copyDateTest.getValueA().year << std::endl;
	std::cout << "Value B: " << copyDateTest.getValueB().month << "/" << copyDateTest.getValueB().day << "/" << copyDateTest.getValueB().year << std::endl;
	//File Output
	output << "Date Copy Testing" << std::endl;
	output << "Value A: " << copyDateTest.getValueA().month << "/" << copyDateTest.getValueA().day << "/" << copyDateTest.getValueA().year << std::endl;
	output << "Value B: " << copyDateTest.getValueB().month << "/" << copyDateTest.getValueB().day << "/" << copyDateTest.getValueB().year << std::endl;

	//Testing Changing Values
	dateTest.setvalueA({ 5,17,2076 });
	dateTest.setvalueB({ 12,3,1998 });

	//Console Output
	std::cout << "Changing Date Testing" << std::endl;
	std::cout << "Value A: " << dateTest.getValueA().month << "/" << dateTest.getValueA().day << "/" << dateTest.getValueA().year << std::endl;
	std::cout << "Value B: " << dateTest.getValueB().month << "/" << dateTest.getValueB().day << "/" << dateTest.getValueB().year << std::endl;
	//File Output
	output << "Changing Date Testing" << std::endl;
	output << "Value A: " << dateTest.getValueA().month << "/" << dateTest.getValueA().day << "/" << dateTest.getValueA().year << std::endl;
	output << "Value B: " << dateTest.getValueB().month << "/" << dateTest.getValueB().day << "/" << dateTest.getValueB().year << std::endl;

	//Close Output File
	output.close();

	system("PAUSE");
	return 0;
}