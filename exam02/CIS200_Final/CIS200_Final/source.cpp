#include <iostream>

struct listrec
{
	char value;
	listrec *next = NULL;
};


//Function Prototypes
void printList(listrec *current_linked_list);
void shallowCopy(listrec *old_linked_list, listrec *&new_linked_list);
void deepCopy(listrec * old_linked_list, listrec *& new_linked_list);

int main()
{
	//Create Manipulation Pointers
	listrec* list1 = new listrec;
	listrec* list2 = new listrec;
	listrec* list3 = new listrec;
	listrec* current = new listrec;
	listrec* temp = new listrec;

	//Set to HEAD
	current = list1;


	//Fill with values
	current->value = 'a';
	current->next = new listrec;
	current = current->next;
	current->value = 'c';
	current->next = new listrec;
	current = current->next;
	current->value = 'w';
	current->next = NULL;

	std::cout << "List 1" << std::endl;
	printList(list1);

	std::cout << "Performing Shallow Copy" << std::endl;
	shallowCopy(list1, list2);

	std::cout << "List 1" << std::endl;
	printList(list1);
	std::cout << "List 2" << std::endl;
	printList(list2);

	std::cout << "Appending 'X' to List 1" << std::endl;

	//Set to HEAD
	current = list1;

	//Iterate Through
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new listrec;
	current = current->next;
	//Fill
	current->value = 'X';

	std::cout << "List 1" << std::endl;
	printList(list1);
	std::cout << "List 2" << std::endl;
	printList(list2);

	//Perform Deep Copy
	std::cout << "Performing Deep Copy" << std::endl;
	deepCopy(list1, list3);

	std::cout << "List 1" << std::endl;
	printList(list1);
	std::cout << "List 3" << std::endl;
	printList(list2);

	std::cout << "Appending 'Z' to List 1" << std::endl;

	//Set to HEAD
	current = list1;
	//Iterate Through
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new listrec;
	current = current->next;
	//Fill
	current->value = 'Z';

	std::cout << "List 1" << std::endl;
	printList(list1);
	std::cout << "List 3" << std::endl;
	printList(list3);

	//Empty List 3
	std::cout << "Emptying List 3" << std::endl;

	current = list3;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}

	list3 = NULL;

	std::cout << "List 1" << std::endl;
	printList(list1);
	std::cout << "List 3" << std::endl;
	printList(list3);

	system("pause");
	return 0;
}

//Prints Linked List Provided of type listrec
void printList(listrec *current_linked_list)
{
	listrec* current;
	current = current_linked_list;

	if (current == NULL)
	{
		std::cout << "Empty" << std::endl;
	}
	else
	{
		while (current->next != NULL)
		{
			std::cout << current->value << ", ";
			current = current->next;
		}
		std::cout << current->value << std::endl;
	}
}

//Creates Shallow copy by pointing to old head
void shallowCopy(listrec * old_linked_list, listrec *& new_linked_list)
{
	new_linked_list = old_linked_list;
}


void deepCopy(listrec * old_linked_list, listrec *& new_linked_list)
{
	listrec* oldCurrent = old_linked_list;
	listrec* newCurrent = new_linked_list;
	char temp;


	while (oldCurrent->next != NULL)
	{
		//Equate Values
		temp = oldCurrent->value;
		newCurrent->value = temp;
		//Create Next New Pointer
		newCurrent->next = new listrec;
		//Move to Next New Pointer
		newCurrent = newCurrent->next;
		//Move to Next Old Pointer
		oldCurrent = oldCurrent->next;
	}
	newCurrent->value = temp;
}