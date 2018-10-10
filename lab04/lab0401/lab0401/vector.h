#pragma once

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
	//Default Contructor
	Vector();
	
	//Size Constructor
	Vector(int s);				//Makes size = s
								//allocate s space
								//	e.g. entries = new int[size],
								//makes all entries 0

	//Copy Constructor
	Vector(const Vector& other);//Makes a deep copy

	//Default Destructor
	~Vector();

	void print();				//Prints out the vector
	void set(int val, int pos);	//Store values in vector

private:

	int size;					//Sets the # of elements used
	int *entries;				//Point to array of integers with size entries
								//	e.g. entries= new int[size]
};


#endif