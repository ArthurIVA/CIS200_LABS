#pragma once
#include "Task.h"	//For Adapting Heap from Int to Task Type

class Queue 
{
private:
	Task queueList[4000];
	int maxSize = 10000;
	int size = 0;
public:
	//Default Constructor
	Queue() 
	{
	}

	//Default Destructor
	~Queue()
	{

	}

	//GETTER COMMANDS

	//Return Size of Queue
	int getSize() 
	{
		return size;
	}

	//Return Left Index
	int getLeftIndex(int parent) 
	{
		return 2 * parent + 1;
	}
	
	//Return Right Index
	int getRightIndex(int parent) 
	{
		return 2 * parent + 2;
	}

	//Return Parent Index
	int getParentIndex(int child) 
	{
		return (child - 1) / 2;
	}

	//OTHER COMMANDS

	//Checking Left Node
	bool hasLeft(int index) 
	{
		return getLeftIndex(index) < size;
	}

	//Checking Right Node
	bool hasRight(int index) 
	{
		return getRightIndex(index) < size;
	}

	//Checking Parent Node
	bool hasParent(int index) 
	{
		return getParentIndex(index) >= 0;
	}

	//Get Left Task
	Task left(int index) 
	{
		return queueList[getLeftIndex(index)];
	}

	//Get Right Task
	Task right(int index) 
	{
		return queueList[getRightIndex(index)];
	}

	//Get Parent Task
	Task parent(int index) 
	{
		return queueList[getParentIndex(index)];
	}

	//Swap Two Tasks @ Index 1 2
	void swap(int indexOne, int indexTwo) 
	{
		Task temp = queueList[indexOne];
		queueList[indexOne] = queueList[indexTwo];
		queueList[indexTwo] = temp;
	}

	//Check if Empty
	bool isEmpty() 
	{
		if (size == 0) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	//PEEKABOO
	Task peek() 
	{
		if (size == 0) 
		{
			return Task();
		}
		else 
		{
			return queueList[0];
		}
	}

	//Autological
	void enqueue(Task newTask, int time) 
	{
		newTask.setTimeAddedToQueue(time);
		queueList[size] = newTask;
		size++;
		heapifyUp();
	}
	
	//Autological
	Task dequeue() 
	{
		if (size == 0) 
		{
			return Task();
		}
		else 
		{
			Task task = queueList[0];
			queueList[0] = queueList[size - 1];
			size--;
			heapifyDown();
			return task;
		}
	}

	void heapifyUp() 
	{
		int index = size - 1;
		while (hasParent(index) && parent(index).getProcessingTime() > queueList[index].getProcessingTime()) 
		{
			swap(getParentIndex(index), index);
			index = getParentIndex(index);
		}
	}

	void heapifyDown() 
	{
		int index = 0;

		while (hasLeft(index)) 
		{
			int smallChildIndex = getLeftIndex(index);

			if (hasRight(index) && right(index).getProcessingTime() < left(index).getProcessingTime()) 
			{
				smallChildIndex = getRightIndex(index);
			}
			if (queueList[index].getProcessingTime() < queueList[smallChildIndex].getProcessingTime()) 
			{
				break;
			}
			else 
			{
				swap(index, smallChildIndex);
			}
			index = smallChildIndex;
		}
	}
};