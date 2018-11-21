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
};

//Class to contain Double Linked List for parameter passing
class sortedList
{
public:
	node* head = NULL;
};

//Function Prototypes
void insertIntegers(sortedList&, std::vector<int>);

int main()
{
	//Declerations
	std::vector<int> integerInputs;	//Vector of Integers for Linked List
	std::ofstream log("log.txt");	//Output Stream for Logging Actions Performed


	//Initial Prompt
	std::cout << "Integers being read from 'integer.dat'" << std::endl;


	system("pause");
	return 0;
}

void insertIntegers(sortedList& list, std::vector<int> input)
{
	node* prior;
	node* current;
	node* next;
	node* temp;

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
			temp->data = input.at(i);
			temp->next = list.head;
		}
		else if (list.head->data == input.at(i))
		{
			std::cout << "Attempted to insert a duplicate " << input.at(i) << "." << std::endl;
		}
		else
		{
			prior = NULL;
			current = list.head;
			
			while (current != NULL && current->data < input.at(i))
			{
				prior = current;
				current = current->next;
			}
			if (current == NULL)
			{
				temp = new node;
				temp->data = input.at(i);
				temp->next = NULL;
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
				prior->next = temp;
			}
		}
	}
}
