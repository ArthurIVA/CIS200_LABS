//Program Name: Processor Simulation
//Programmer Name: Arthur Aigeltinger IV
//Description: Use a binary heap priority queue to simulate jobs randomly being inserted into a processor
//Date Created: 12/03/18

//C++ Libraries
#include <ctime>
#include <fstream> 
#include <iostream>
#include <string>

//Created Headers
#include "Task.h"
#include "Processor.h"
#include "Queue.h"

//Define Simulation Constants
//Modify for Testing
#define PROCESSOR_COUNT 3
#define A_COUNT 2000
#define B_COUNT 1000
#define C_COUNT 400
#define D_COUNT 333

//I told myself I would never use this, but this program is just to large to go without.
using namespace std;

int main() 
{
	//Declare Output Stream
	ofstream output;
	output.open("log.dat");

	//Create Binary Heap Priority Queue
	Queue taskQueue = Queue();

	//Declare Arrays for Initial Job Creation
	Task a[A_COUNT];
	Task b[B_COUNT];
	Task c[C_COUNT];
	Task d[D_COUNT];

	//Declare and Initialize Metric Holder Variables
	int queueSize = 0;
	int totalQueueSize = 0;
	int totalEnqueued = 0;
	int totalAJobs = 0;
	int totalBJobs = 0;
	int totalCJobs = 0;
	int totalDJobs = 0;
	int totalWaitTimeInQueue = 0;
	int jobsInterrupted = 0;
	int jobsCompleted = 0;
	int maxQueueSize = 0;
	double averageTimeInQueue = 0;
	double averageQueueSize = 0;

	//Declare Set of Processors
	Processor processors[PROCESSOR_COUNT];

	//Fill in Processors
	for (int i = 0; i < PROCESSOR_COUNT; i++) 
	{
		//Declare NEW
		Processor newProcessor = Processor();
		//Insert
		processors[i] = newProcessor;
	}

	//Fill Array of 'A' Tasks
	int prevArrival = 0;	//Create Iterator
	for (int i = 0; i < A_COUNT; i++) 
	{
		//Declare NEW
		Task newTask = Task();
		//Set Job Type
		newTask.setType('a');
		//Set SEED to System Time
		srand(time(0));
		//Generate Arrival Time
		newTask.setArrivalTime(prevArrival + (4 + (rand() % 3)));
		//SEED
		srand(time(0));
		//Generate Processing Time
		newTask.setProcessingTime(1 + (rand() % 5));

		//Insert Into Array
		a[i] = newTask;

		//Set Previous Arrival for Next Job Generation
		prevArrival = newTask.getArrivalTime();
	}

	//Fill Array of 'B' Tasks
	prevArrival = 0;	//Return Iterator
	for (int i = 0; i < B_COUNT; i++) 
	{
		//Declare NEW
		Task newTask = Task();
		//Set Job Type
		newTask.setType('b');
		//Set SEED to System Time
		srand(time(0));
		//Generate Arrival Time
		newTask.setArrivalTime(prevArrival + (9 + (rand() % 3)));
		//SEED
		srand(time(0));
		//Generate Processing Time
		newTask.setProcessingTime(6 + (rand() % 5));
	
		//Insert Into Array
		b[i] = newTask;

		//Set Previous Arrival for Next Job Generation
		prevArrival = newTask.getArrivalTime();
	}

	//Fill Array of 'C' Tasks
	prevArrival = 0;	//Return Iterator
	for (int i = 0; i < C_COUNT; i++) 
	{
		//Declare NEW
		Task newTask = Task();
		//Set Job Type
		newTask.setType('c');
		//Set SEED to System Time
		srand(time(0));
		//Generate Arrival Time
		newTask.setArrivalTime(prevArrival + (24 + (rand() % 3)));
		//SEED
		srand(time(0));
		//Generate Processing Time
		newTask.setProcessingTime(11 + (rand() % 5));
		
		//Insert Into Array
		c[i] = newTask;
	
		//Set Previous Arrival for Next Job Generation
		prevArrival = newTask.getArrivalTime();
	}

	//Fill Array of 'D' Tasks
	prevArrival = 0;	//Return Iterator
	for (int i = 0; i < D_COUNT; i++) 
	{
		//Declare NEW
		Task newTask = Task();
		newTask.setType('d');
		//IMMEDIEATELY IDENTIFY THAT THESE ARE HIGH PRIORITY
		newTask.setHighPriority(true);
		//Seet SEED to System Time
		srand(time(0));
		//Generate Arrival Time
		newTask.setArrivalTime(prevArrival + (25 + (rand() % 11)));
		//SEED
		srand(time(0));
		//Generate Processing Time
		newTask.setProcessingTime(8 + (rand() % 5));
		
		//Insert Into Array
		d[i] = newTask;
	
		//Set Previous Arrival for Next Job Generation
		prevArrival = newTask.getArrivalTime();
	}

	//Declare Iterators and Time Tick Holder
	int aIterator = 0;
	int bIterator = 0;
	int cIterator = 0;
	int dIterator = 0;

	int time = 1;

	//Start TICKING
	while (time <= 10000) 
	{
		//Generate First Line
		output << time << ") ";
		
		//Attempt Inserting A Jobs
		if (a[aIterator].getArrivalTime() == time) 
		{
			output << "Job A Arrived; ";
			totalAJobs++;
			bool added = false;

			for (int i = 0; i < PROCESSOR_COUNT; i++) 
			{
				if (processors[i].getEmpty()) 
				{
					if (taskQueue.isEmpty() == true) 
					{
						output << " Begin Processing Job " << a[aIterator].getType() << " , CPU: " << i << "; ";
						processors[i].setCurrentTask(a[aIterator]);
						added = true;
					}
				}
			}
			if (added == false) 
			{
				taskQueue.enqueue(a[aIterator], time);
				output << "Queued Job " << a[aIterator].getType() << " , Total Queue Size: " << taskQueue.getSize() << "; ";
			}
			aIterator++;
		}

		//Attempt Inserting B Jobs
		if (b[bIterator].getArrivalTime() == time) 
		{
			output << "Job B Arrived; ";
			totalBJobs++;
			bool added = false;
			for (int i = 0; i < PROCESSOR_COUNT; i++) 
			{
				if (processors[i].getEmpty()) 
				{
					if (taskQueue.isEmpty() == true) 
					{
						output << " Begin Processing Job " << b[bIterator].getType() << " , CPU: " << i << "; ";
						processors[i].setCurrentTask(b[bIterator]);
						added = true;
					}
				}
			}
			if (added == false) 
			{
				taskQueue.enqueue(b[bIterator], time);
				output << "Queued Job " <<b[bIterator].getType() << " , Total Queue Size: " << taskQueue.getSize() << "; ";
			}
			bIterator++;
		}

		//Attempt Inserting B Jobs
		if (c[cIterator].getArrivalTime() == time) 
		{
			output << "Job C Arrived; ";
			totalCJobs++;
			bool added = false;
			for (int i = 0; i < PROCESSOR_COUNT; i++) 
			{
				if (processors[i].getEmpty()) 
				{
					if (taskQueue.isEmpty() == true) 
					{
						output << " Begin Processing Job " << c[cIterator].getType() << " , CPU: " << i << "; ";
						processors[i].setCurrentTask(c[cIterator]);
						added = true;
					}
				}
			}	
			if (added == false) 
			{
				taskQueue.enqueue(c[cIterator], time);
				output << "Queued job " << c[cIterator].getType() << " , Total Queue Size: " << taskQueue.getSize() << "; ";
			}
			cIterator++;
		}


		if (d[dIterator].getArrivalTime() == time) 
		{
			output << "Job D Arrived; ";
			totalDJobs++;
			if (d[dIterator].getHighPriority() == true) 
			{

				int highest = -1;
				int empty = -1;
				for (int i = 0; i < PROCESSOR_COUNT; i++) 
				{
					if (processors[i].getEmpty()) 
					{
						empty = i;
					}
					else if (highest == -1) 
					{
						highest = i;
					}
					else if (processors[highest].getTimeLeft() < processors[i].getTimeLeft()) 
					{
						highest = i;
					}
				}
				Task suspended;
				if (empty != NULL) 
				{
					suspended = processors[empty].suspend(d[dIterator]);
					jobsInterrupted++;
				}
				else if (highest != NULL) 
				{
					suspended = processors[highest].suspend(d[dIterator]);
					jobsInterrupted++;
				}

				taskQueue.enqueue(suspended, time);
			}
			else
			{
				//Insert Task Into Queue
				bool added = false;
				for (int i = 0; i < PROCESSOR_COUNT; i++) 
				{
					if (processors[i].getEmpty()) 
					{
						if (taskQueue.isEmpty() == true) 
						{
							output << " Begin Processing Job " << d[dIterator].getType() << " , CPU: " << i << "; ";
							processors[i].setCurrentTask(d[dIterator]);
							added = true;
						}
					}
					if (added == false) 
					{
						taskQueue.enqueue(b[bIterator], time);
						output << "Queued Job " << d[dIterator].getType() << " , Total Queue Size: " << taskQueue.getSize() << "; ";
					}
				}
			}
			dIterator++;
		}
	
		//Insert Task Into Processors
		for (int i = 0; i < PROCESSOR_COUNT; i++) 
		{
			if (processors[i].getEmpty()) 
			{
				if (taskQueue.isEmpty() == false) 
				{
					Task temp = taskQueue.dequeue();
					totalWaitTimeInQueue += time - temp.getTimeAddedToQueue();
					output << " Begin Processing Job " << temp.getType() << " , CPU: " << i << "; ";
					processors[i].setCurrentTask(temp);
				}
				else 
				{
					output << "Processor " << i << " Idle, Total Idle Time " << processors[i].getIdleTime() << "; ";
				}
			}
		}

		//When Job Completed, Increment Jobs Completed
		for (int i = 0; i < PROCESSOR_COUNT; i++) 
		{
			if (processors[i].process() == true) 
			{
				output << "Job " << processors[i].getCurrentTask().getType() << " Completed on CPU " << i << "; ";
				jobsCompleted++;
			}
		}

		//Calculate Extra Metrics
		if (taskQueue.getSize() > maxQueueSize) 
		{
			maxQueueSize = taskQueue.getSize();
		}

		queueSize = taskQueue.getSize();
		totalQueueSize += taskQueue.getSize();
		averageQueueSize = (double)totalQueueSize / (double)time;

		if (totalEnqueued != 0) 
		{
			averageTimeInQueue = (double)totalWaitTimeInQueue / (double)totalEnqueued;
		}

		//Metrics to Print @ 500 Cycles and 10,000 Cycles
		if (time == 500 || time == 10000) 
		{

			std::cout << endl << "Metrics For First " << time << " CPU Cycles" << endl;
			std::cout << "Queue Size: " << queueSize << endl;
			std::cout << "Total Queue Size: " << totalQueueSize << endl;
			std::cout << "Average Queue Size: " << averageQueueSize << endl;
			std::cout << "Total Wait Time in Queue: " << totalWaitTimeInQueue << endl;
			std::cout << "Average Wait Time in Queue: " << averageTimeInQueue << endl;
			std::cout << "Max Queue Size: " << maxQueueSize << endl;

			for (int i = 0; i < PROCESSOR_COUNT; i++) 
			{
				std::cout << "CPU " << i << " Total Idle Time: " << processors[i].getIdleTime() << endl;
				std::cout << "CPU " << i << " Total Tasks Completed: " << processors[i].getTasksCompleted() << endl;
				std::cout << "CPU " << i << " Percent Usage: " << (double)((double)(time - processors[i].getIdleTime()) / (double)time)*100.0 << "%" << endl;
			}

			std::cout << "Total A Tasks: " << totalAJobs << endl;
			std::cout << "Total B Tasks: " << totalBJobs << endl;
			std::cout << "Total C Tasks: " << totalCJobs << endl;
			std::cout << "Total D Tasks: " << totalDJobs << endl;
			std::cout << "Total Tasks Completed: " << jobsCompleted << endl;
			std::cout << "Total Tasks Interrupted: " << jobsInterrupted << endl;
			std::cout << "Number of Processors: " << PROCESSOR_COUNT << endl;

		}
		//Generate New Line In Output
		output << std::endl;
		//Iterate Time Tick
		time++;
	}
	//Close Output
	output.close();
	system("pause");
	return 0;
}