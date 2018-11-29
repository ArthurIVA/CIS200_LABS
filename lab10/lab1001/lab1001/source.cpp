//Program Name: TYPENAME TYPENAME TYPENAME
//Programmer Name: Arthur Aigeltinger IV
//Description: TYPENAME
//Date Created: 11/28/2018

#include <fstream>
#include <iostream>
#include <string>

//Declare Global Constants
const int N = 5;

//Define Linked List Node
struct node
{
	double data;
	node* next;
};

//Declare Class Containing Linked List
class sortedList
{
public:
	node* head;
};

//Template Function Prototypes
template<typename T>
T minMaxFunc(T(&inArray)[N], std::string choice);

template<typename T, size_t N>
void sortLinkedList(T(&inArray)[N], sortedList&);


int main()
{
	//Declare Input/Output Streams
	std::ifstream input("data.dat");
	std::ofstream output("out.txt");

	//Declare Array for Input Data
	//Stack(s) 2
	int intArray[N];
	double doubleArray[N];

	//Declare Linked List
	//Stack(s) 1
	sortedList list1;
	sortedList list2;

	//Declare Minimums and Maximums
	int intMin, intMax;
	double dubMin, dubMax;

	//Check File
	if (!input.is_open())	//Is It Open?
	{
		std::cout << "NO FILE FOUND" << std::endl;
		output << "NO FILE FOUND" << std::endl;
		system("pause");
		return 0;
	}
	else if (input.peek() == std::ifstream::traits_type::eof())	//Is It Empty?
	{
		std::cout << "File Was Empty" << std::endl;
		output << "Initial File Was Empty" << std::endl;
		system("pause");
		return 0;
	}
	else	//FILE HAS STUFF IN IT
	{
		//Fill Integer Array
		for (int i = 0; i < N; i++)
		{
			input >> intArray[i];
		}

		//Fill Double Array
		for (int i = 0; i < N; i++)
		{
			input >> doubleArray[i];
		}
	}

	//Attempt Sorting Stacks
	sortLinkedList(intArray, list1);
	sortLinkedList(doubleArray, list2);

	//Call for Minimum and Maximum
	intMin = minMaxFunc(intArray, "Min");
	intMax = minMaxFunc(intArray, "Max");
	dubMin = minMaxFunc(doubleArray, "Min");
	dubMax = minMaxFunc(doubleArray, "Max");

	//Print to User
	std::cout << "Integer Minimum : " << intMin << std::endl;
	std::cout << "Integer Maximum : " << intMax << std::endl;
	std::cout << "Double  Minimum : " << dubMin << std::endl;
	std::cout << "Double  Maximum : " << dubMax << std::endl;

	//Print to FILE
	output << "Integer Minimum : " << intMin << std::endl;
	output << "Integer Maximum : " << intMax << std::endl;
	output << "Double  Minimum : " << dubMin << std::endl;
	output << "Double  Maximum : " << dubMax << std::endl;

	//Formatting
	std::cout << std::endl; 
	output << std::endl;

	//Print Stack 1 to User and File
	std::cout << "INTEGER STACK " << std::endl;
	output << "INTEGER STACK " << std::endl;
	
	//Prepare to Print Stack 1
	node* current;
	current = list1.head;

	while (current->next != NULL)
	{
		//Print
		std::cout << current->data << std::endl;
		output << current->data << std::endl;
		//Move
		current = current->next;
	}

	//Print Final
	std::cout << current->data << std::endl;
	output << current->data << std::endl;

	//Print Stack 2 to User and File
	std::cout << "DOUBLE STACK" << std::endl;
	output << "DOUBLE STACK" << std::endl;

	//Prepare to Print Stack 2
	current = list2.head;

	while (current->next != NULL)
	{
		//Print
		std::cout << current->data << std::endl;
		output << current->data << std::endl;
		//Move
		current = current->next;
	}

	//Print Final
	std::cout << current->data << std::endl;
	output << current->data << std::endl;

	current = NULL;

	system("pause");
	return 0;
}

template<typename T>
T minMaxFunc(T(&inArray)[N], std::string choice)
{
	//Stack 1
	sortedList list;


	
	sortLinkedList(inArray, list);

	if (choice == "Min")
	{
		return list.head->data;
	}
	else if (choice == "Max")
	{
		//Manipulation Nodes
		node* current;
		current = list.head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		return current->data;
	}
	else
	{
		std::cout << "Silly goose, that's not an option!" << std::endl;
	}

	return T();
}

/*
If you find this note, please forgive me for not writing this exactly as a stack.
I had come so far before things totally made sense and did not wish to begin anew
This solution still provides the correct results, amen.
*/

template<typename T, size_t N>
void sortLinkedList(T(&inArray)[N], sortedList & list)
{
	node* prior;
	node* current;
	node* temp;

	list.head = NULL;

	//BEGIN FILLING LINKED LIST
	for (int i = 0; i < N; i++)
	{
		if (list.head == NULL)	//If Empty, Create Head
		{
			temp = new node;
			temp->data = inArray[i];
			temp->next = NULL;
			list.head = temp;
		}
		else if (list.head->data > inArray[i])	//Insert One Greater
		{
			temp = new node;
			temp->next = list.head;
			temp->data = inArray[i];

			list.head = temp;

		}
		else if (list.head->data == inArray[i])
		{
			std::cout << "Attempted to insert a duplicate " << inArray[i] << "." << std::endl;
		}
		else
		{
			prior = NULL;
			current = list.head;

			while (current != NULL && (current->data < inArray[i]))
			{
				prior = current;
				current = current->next;
			}
			if (current == NULL)
			{
				temp = new node;
				temp->data = inArray[i];
				temp->next = NULL;
				prior->next = temp;
			}
			else if (current->data == inArray[i])
			{
				std::cout << "Attempted to insert a duplicate " << inArray[i] << "." << std::endl;
			}
			else
			{
				temp = new node;
				temp->data = inArray[i];
				temp->next = current;
				prior->next = temp;
			}
		}
	}
	//END FILLING LINKED LIST
}