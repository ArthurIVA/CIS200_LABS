#include <iostream>
#include <string>

//Structure for Linked List
struct sortedListNode
{
	char letter;
	int occur;
	sortedListNode * next;
};

//Class for Linked List to be passed into functions
class arraySortedList
{
public:
	sortedListNode * head = NULL;
};

//Function Prototypes
void fromString(arraySortedList&, std::string);
void printList(arraySortedList&);

int main()
{
	//Declare Character Arrays for User Input
	std::string word1;
	std::string word2;
	std::string word3;

	//Declare Head of Linked Lists
	arraySortedList list1;
	arraySortedList list2;
	arraySortedList list3;
	
	//Prompt User for Input
	std::cout << "Please Enter The First Word: ";
	std::cin >> word1;
	std::cout << "Please Enter The Second Word: ";
	std::cin >> word2;

	//Compute and Print First Word Details
	std::cout << std::endl << "First Word Details " << std::endl;
	fromString(list1, word1);
	printList(list1);

	//Compute abd Print Second Word Details
	std::cout << std::endl << "Second Word Details " << std::endl;
	fromString(list2, word2);
	printList(list2);

	word3 = word1 + word2; //Operator Overloading*															*technically

	//Compute and Print Combined Word Details
	std::cout << std::endl << "Combined Word Details " << std::endl;
	fromString(list3, word3);
	printList(list3);

	system("pause");
	return 0;
}

//Description: Take in word and linked list, fill the linked list with the letters in alphabetical order.
//Pre-Condition: Word should just include lower case letters
//Post-Condition: Sorted Link LIST!
void fromString(arraySortedList& list, std::string word)
{
	//Declare Movement Nodes
	sortedListNode * prior;
	sortedListNode * current;
	sortedListNode * temp;

	//BEGIN Corrected From Class
	for (int i = 0; i < word.length(); i++)
	{
		if (list.head == NULL)
		{
			temp = new sortedListNode;
			temp->letter = word.at(i);
			temp->occur = 1;
			temp->next = NULL;
			list.head = temp;
		}
		else if (list.head->letter > word.at(i)) {
			temp = new sortedListNode;
			temp->letter = word.at(i);
			temp->occur = 1;
			temp->next = list.head;
			list.head = temp;
		}
		else if (list.head->letter == word.at(i))
		{
			list.head->occur++;
		}
		else
		{
			prior = NULL;
			current = list.head;

			while (current != NULL && current->letter < word.at(i))
			{
				prior = current;
				current = current->next;
			}
			if (current == NULL) {
				temp = new sortedListNode;
				temp->letter = word.at(i);
				temp->occur = 1;
				temp->next = NULL;
				prior->next = temp;
			}
			else if (current->letter == word.at(i))
			{
				current->occur++;
			}
			else
			{
				temp = new sortedListNode;
				temp->letter = word.at(i);
				temp->occur = 1;
				temp->next = current;
				prior->next = temp;
			}
		}
	}
	//END Corrected Code From Class
}

//Description: Print out linked list
//Pre-Condition: A filled linked list
//Post-Condition: A printed linked list
void printList(arraySortedList & list1)
{
	//Declare and Set Current Marker
	sortedListNode * current;
	current = list1.head;

	//If Good, Print all Characters
	if (current == NULL)
	{

	}
	else
	{
		std::cout << "List of Characters     : ";

		while (current != NULL)
		{
			std::cout << current->letter;
			current = current->next;
			std::cout << ", ";
		}
	}

	//Formatting
	std::cout << std::endl;

	//Reset Current Marker
	current = list1.head;

	//If Good, Print all Character Occurances
	if (current == NULL)
	{

	}
	else
	{
		std::cout << "Occurance of Characters: ";

		while (current != NULL)
		{
			std::cout << current->occur;
			current = current->next;
			std::cout << ", ";
		}
	}

	//Formatting
	std::cout << std::endl;
}