#include "Processor.h"

//Default Constructor
Processor::Processor()
{
}

//Default Destructor
Processor::~Processor()
{
}

//SETTER COMMANDS
void Processor::setCurrentTask(Task newTask)
{
	currentTask = newTask;
	empty = false;
}


//GETTER COMMANDS

//Check if Tasks Are Completed
int Processor::getTasksCompleted()
{
	return tasksCompleted;
}

//Return Time Left on Current Task
int Processor::getTimeLeft()
{
	if (empty == false) {
		return currentTask.getProcessingTime();
	}
	else {
		return -1;
	}
}

//Check if Empty
int Processor::getEmpty()
{
	return empty;
}

//Check Idle Time
int Processor::getIdleTime()
{
	return idleTime;
}

//Check Task Count
int Processor::getTaskCount()
{
	return taskCount;
}

//Check Tasks Interrupted 
int Processor::getTasksInterrupted()
{
	return tasksInterrupted;
}

Task Processor::getCurrentTask()
{
	return currentTask;
}

//OTHER COMMANDS

//Return Current Task and Insert New Task
Task Processor::suspend(Task newTask)
{
	if (empty == false)
	{
		Task oldTask = currentTask;
		currentTask = newTask;
		tasksInterrupted++;
		empty = false;
		return oldTask;
	}
}

//Modify Task Currently Inserted and Adjust Flags
bool Processor::process()
{
	if (empty == false) {
		int time = currentTask.getProcessingTime();
		currentTask.setProcessingTime(time - 1);
		if (currentTask.getProcessingTime() == 0) {
			empty = true;
			tasksCompleted++;
			return true;
		}
		else if (currentTask.getProcessingTime() < 0) {
			empty = true;
			return false;
		}
		else
		{
			empty = false;
			return false;
		}
	}
	else {
		idleTime++;
		empty = true;
		return false;
	}
}
