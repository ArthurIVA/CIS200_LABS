#pragma once
#include <cstdlib>
class Task
{
private:

	int arrivalTime = NULL;
	int processingTime = NULL;
	char type = NULL;
	bool highPriority = NULL;
	int timeAddedToQueue = NULL;

public:
	//Default Constructor 
	Task();
	//Default Destructor
	~Task();

	//Setter Commands
	void setArrivalTime(int x);
	void setProcessingTime(int x);
	void setType(char x);
	void setHighPriority(bool x);
	void setTimeAddedToQueue(int x);

	//Getter Commands
	int getArrivalTime();
	int getProcessingTime();
	char getType();
	bool getHighPriority();
	int getTimeAddedToQueue();

};

