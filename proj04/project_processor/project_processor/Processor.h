#pragma once
#include "Task.h"
class Processor
{
private:

	bool empty = true;
	Task currentTask;
	int idleTime = 0;
	int taskCount = 0;
	int tasksCompleted = 0;
	int tasksInterrupted = 0;

public:

	//Default Constructor
	Processor();
	//Default Destructor
	~Processor();

	//Setter Commands
	void setCurrentTask(Task newTask);

	//Getter Commands
	int getTasksCompleted();
	int getTimeLeft();
	int getEmpty();
	int getIdleTime();
	int getTaskCount();
	int getTasksInterrupted();
	Task getCurrentTask();

	//Other Commands
	Task suspend(Task newTask);
	bool process();

	

	
};

