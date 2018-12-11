#include "Task.h"

//Default Constructor
Task::Task()
{
	//Set to FALSE for all jobs except 'D'
	setHighPriority(false);
}

//Default Destructor
Task::~Task()
{
}

//SETTER COMMANDS

//Set Arrival Time
void Task::setArrivalTime(int x)
{
	arrivalTime = x;
}

//Set Processing Time
void Task::setProcessingTime(int x)
{
	processingTime = x;
}

//Check Job Type
void Task::setType(char x)
{
	type = x;
}

//Set Priority
void Task::setHighPriority(bool x)
{
	highPriority = x;
}

//Set Time Added to Queue
void Task::setTimeAddedToQueue(int x)
{
	timeAddedToQueue = x;
}

//GETTER COMMANDS

//Check Arrival Time
int Task::getArrivalTime()
{
	return arrivalTime;
}

//Check Processing Time
int Task::getProcessingTime()
{
	return processingTime;
}

//Check Job Type
char Task::getType()
{
	return type;
}

//Check Priority
bool Task::getHighPriority()
{
	return highPriority;
}

//Check Time Added to Queue
int Task::getTimeAddedToQueue()
{
	return timeAddedToQueue;
}
