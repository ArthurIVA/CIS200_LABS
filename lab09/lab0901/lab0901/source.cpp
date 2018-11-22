//Program Name: THIS PROGRAM MADE ME WANT TO DIE.
//Programmer Name: Arthur Aigeltinger IV
//Description: 4 lines screwed this up for more hours than I care to count.
//Date Created: 11/19/18

#include <cctype>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

//Dooubly Linked List Node
struct node
{
	int data;	//Contains Integer from File or User Input
	node* prev;	//Pointer to previous node
	node* next;	//Pointer to next node
	node* evenPrev;	//Pointer to previous even node
	node* evenNext;	//Pointer to next even node
};

//Class to contain Double Linked List for parameter passing
class sortedList
{
public:
	node* head = NULL;
	node* tail = NULL;
	node* evenHead = NULL;
	node* evenTail = NULL;
};

//Function Prototypes
void insertIntegers(sortedList&, std::vector<int>);	//Fill Linked List with Integers from Buffer Vector
void printList(sortedList&, char);					//Print Linked List in Ascending or Descending Order
void printEvenList(sortedList&, char);				//Print Even Sub-List in Ascending or Descending Order

int main()
{
	//Declerations
	std::vector<int> integerInputs;		//Vector of Integers for Linked List
	std::ifstream input("integer.dat");	//Input Stream Adding Initial Integers
	std::ofstream log("log.txt");		//Output Stream for Logging Actions Performed
	char option = ' ';					//Holder Variable for Ascending/Descending Option
	int choice = 1;						//Holder Variable for Menu Options
	int tempInput = NULL;				//Holder Variable for filling Vector

	log << "Program Starting" << std::endl;

	sortedList list;

	//Initial Prompt
	std::cout << "Integers being read from 'integer.dat'" << std::endl << std::endl;

	if (!input.is_open())	//Is It Open?
	{
		std::cout << "NO FILE FOUND" << std::endl;
		log << "NO FILE FOUND" << std::endl;
	}
	else if (input.peek() == std::ifstream::traits_type::eof())	//Is It Empty
	{
		std::cout << "File Was Empty" << std::endl;
		log << "Initial File Was Empty" << std::endl;
	}
	else	//READ THAT SHIZ
	{
		//Check for negative numbers

		while (!input.eof())
		{
			input >> tempInput;

			if (tempInput <= 0)
			{
				std::cout << "ATTEMPTED TO READ NEGATIVE FROM FILE" << std::endl;
				log << "File Contained Negative Integer" << std::endl;
			}
			else
			{
			integerInputs.push_back(tempInput);
			}
		}
		insertIntegers(list, integerInputs);	//Fill Linked List Initially
	}

	//Begin Menu
	do
	{
		std::cout << "Please Select an Option" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "(1) Manually Add Integers" << std::endl;						//TODO
		std::cout << "(2) Manually Delete Integer" << std::endl;					//TODO
		std::cout << "(3) Print Full Linked List" << std::endl;	
		std::cout << "(4) Print Even Linked List" << std::endl;						//TODO
		std::cout << "(0) QUIT" << std::endl << std::endl;

		std::cout << "Choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			std::cout << "Quitting Program" << std::endl;
			break;
		case 1:	//Adding Integers
			std::cout << "You May Only Add POSITIVE Integers" << std::endl;
			std::cout << "Enter '0' to EXIT" << std::endl << std::endl;
			log << "Began Manually Entering Integers" << std::endl;

			do
			{
				std::cout << "Integer: ";
				std::cin >> tempInput;

				if (tempInput < 0)
				{
					std::cout << "INVALID INPUT" << std::endl;
					log << "Tried Invalid Integer: " << tempInput << std::endl;
				}
				else if (tempInput > 0)
				{
					integerInputs.push_back(tempInput);
					log << "Valid Integer Added: " << tempInput << std::endl;
				}
			} while (tempInput != 0);

			log << "Exited Manual Entry" << std::endl;
			insertIntegers(list, integerInputs);
			break;
		case 2:
			std::cout << "You are removing POSITIVE Integers" << std::endl;
			std::cout << "Enter '0' to EXIT" << std::endl << std::endl;
			log << "Began Manually Deleting Integers" << std::endl;

			do
			{
				std::cout << "Integer: ";
				std::cin >> tempInput;

				if (tempInput < 0)
				{
					std::cout << "INVALID INPUT" << std::endl;
					log << "Tried Invalid Integer: " << tempInput << std::endl;
				}
				else if (tempInput > 0)
				{
					for (int i = 0; i < integerInputs.size(); i++)
					{
						if (integerInputs.at(i) == tempInput)
						{
							integerInputs.erase(integerInputs.begin() + i);
							integerInputs.shrink_to_fit();
							log << "Valid Integer Deleted: " << tempInput << std::endl;
						}
					}
					
				}
			} while (tempInput != 0);

			insertIntegers(list, integerInputs);
			break;
		case 3:

			do
			{
				std::cout << "Print In (A)scending / (D)escending Order?" << std::endl;
				std::cin >> option;
				option = toupper(option);	//Uppercase

				switch (option)
				{
				case 'A':
					printList(list, 'A');
					log << "Printed All Integers In Ascending Order" << std::endl;
					break;
				case 'D':
					printList(list, 'D');
					log << "Printed All Integers In Descending Order" << std::endl;
					option = 'A';
					break;
				default:
					std::cout << "INVALID OPTION" << std::endl;
					break;
				}
			} while (option != 'A');

			break;
		case 4:

			do
			{
				std::cout << "Print In (A)scending / (D)escending Order?" << std::endl;
				std::cin >> option;
				option = toupper(option);	//Uppercase

				switch (option)
				{
				case 'A':
					printEvenList(list, 'A');
					log << "Printed Even Integers In Ascending Order" << std::endl;
					break;
				case 'D':
					printEvenList(list, 'D');
					log << "Printed Even Integers In Descending Order" << std::endl;
					option = 'A';
					break;
				default:
					std::cout << "INVALID OPTION" << std::endl;
					break;
				}
			} while (option != 'A');

			break;
		default:
			std::cout << "INVALID MENU OPTION" << std::endl;
			break;
		}
		

	} while (choice != 0);

	log << "Program Ending" << std::endl;
	log.close();

	system("pause");
	return 0;
}

//Description: Take Vector of Integers and Insert them in order into a doubly linked list
//Pre-condition: Filled Vector and compatible linked list
//Post-Condition: Filled Linked List
void insertIntegers(sortedList& list, std::vector<int> input)
{
	node* prior;
	node* current;
	node* currentEven;
	node* next;
	node* temp;

	//ERASING FILLED LINK LIST
	current = list.head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	list.head = NULL;
	list.tail = NULL;
	list.evenHead = NULL;
	list.evenTail = NULL;
	//END ERASING

	//BEGIN FILLING LINKED LIST
	for (int i = 0; i < input.size(); i++)
	{
		if (list.head == NULL)	//If Empty, Create Head
		{
			temp = new node;
			temp->data = input.at(i);
			temp->next = NULL;
			temp->prev = NULL;
			list.head = temp;
		}
		else if (list.head->data > input.at(i))	//Insert One Greater
		{
			temp = new node;
			temp->next = list.head;
			temp->prev = NULL;
			temp->data = input.at(i);

			list.head->prev = temp;
			list.head = temp;
			
		}
		else if (list.head->data == input.at(i))
		{
			std::cout << "Attempted to insert a duplicate " << input.at(i) << "." << std::endl;
		}
		else
		{
			prior = NULL;
			current = list.head;
			
			while (current != NULL && (current->data < input.at(i)))
			{
				prior = current;
				current = current->next;
			}
			if (current == NULL)
			{
				temp = new node;
				temp->data = input.at(i);
				temp->next = NULL;
				temp->prev = prior;
				prior->next = temp;
			}
			else if (current->data == input.at(i))
			{
				std::cout << "Attempted to insert a duplicate " << input.at(i) << "." << std::endl;
			}
			else
			{
				temp = new node;
				temp->data = input.at(i);
				temp->next = current;
				temp->prev = prior;
				prior->next = temp;
				current->prev = temp;
			}
		}
	}
	//END FILLING LINKED LIST

	//BEGIN LINKING TAIL
	current = list.head;	//Reset Current to Head
	
	//Loop to define PREV pointers
	for (int i = 0; i < input.size(); i++)
	{
		if (current->next != NULL)
		{
		current->next->prev = current;
		current = current->next;
		}
	}

	list.tail = current;	//Define Tail as End
	//END LINKING TAIL

	//BEGIN LINKING EVEN HEAD SUBLIST
	current = list.head;
	temp = list.head;

	while (temp != NULL)
	{
		if (temp->data % 2 == 0)
		{
			if (list.evenHead == NULL)
			{
				list.evenHead = temp;
				list.evenTail = temp;
				current = list.evenHead;
			}
			else
			{
				list.evenTail = temp;
				next = temp;
				next->evenPrev = current;
				current->evenNext = next;

				current = next;
				next = NULL;
			}
		}
		temp = temp->next;
	}

	//Cover up the evidence of the murder...
	if (list.evenHead != NULL)
	{
		list.evenHead->evenPrev = NULL;
		list.evenTail->evenNext = NULL;
	}
}

//Description: Take in filled linked list an control character to print it in one of two ways
//Pre-condition: Sorted Linked List, choice character
//Post-Condition: List Printed in Ascending or Descending Order
void printList(sortedList& list, char choice)
{
	//Declare and Set Current Marker
	node * current;

	//If Good, Print all Integers
	if (choice == 'A')
	{
		//PRINT ASCENDING
		current = list.head;

		if (current == NULL)
		{
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			std::cout << "List of Ascending Integers  : ";

			while (current != NULL)
			{
				std::cout << current->data;
				current = current->next;
				std::cout << " ";
			}
		}

		//Formatting
		std::cout << std::endl << std::endl;
	}

	if (choice == 'D')
	{
		//PRINT DESCENDING
		current = list.tail;

		if (current == NULL)
		{
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			std::cout << "List of Descending Integers : ";

			while (current != NULL)
			{
				std::cout << current->data;
				current = current->prev;
				std::cout << " ";
			}
		}

		//Formatting
		std::cout << std::endl << std::endl;
	}
}

//Description: Take in filled linked list an control character to print it in one of two ways
//Pre-condition: Sorted Linked List, choice character
//Post-Condition: Even List Printed in Ascending or Descending Order
void printEvenList(sortedList& list, char choice)
{
	//Declare and Set Current Marker
	node * current;

	//If Good, Print all Integers
	if (choice == 'A')
	{
		//PRINT ASCENDING
		current = list.evenHead;

		if (current == NULL)
		{
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			std::cout << "List of Even Ascending Integers  : ";

			while (current != NULL)
			{
				std::cout << current->data;
				current = current->evenNext;
				std::cout << " ";
			}
		}

		//Formatting
		std::cout << std::endl << std::endl;
	}

	if (choice == 'D')
	{
		//PRINT DESCENDING
		current = list.evenTail;

		if (current == NULL)
		{
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			std::cout << "List of Even Descending Integers : ";

			while (current != NULL)
			{
				std::cout << current->data;
				current = current->evenPrev;
				std::cout << " ";
			}
		}

		//Formatting
		std::cout << std::endl << std::endl;
	}
}
