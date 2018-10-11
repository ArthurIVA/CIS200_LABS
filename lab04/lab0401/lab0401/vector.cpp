#include "vector.h"
//PUBLIC

//STRUCTOR

//Default Constructor
Vector::Vector()
{
	size = 0;
	entries = new int[size];
}

//Size Constructor
Vector::Vector(int s)
{
	size = s;

	if (size < 0)
	{
		std::cout << "ERROR: SIZE CANNOT BE < 0" << std::endl;
		size = 0;
	}
	else
	{
		size = s;
		entries = new int[size];

		for (int i = 0; i < size; i++)
		{
			entries[i] = 0;
		}
	}
	
}

//Copy Constructor
Vector::Vector(const Vector & other)
{
	size = other.size;

	entries = new int[size];

	for (int i = 0; i < size; i++)
	{
		entries[i] = other.entries[i];
	}
}

//DESTRUCTOR
Vector::~Vector()
{
	delete(entries);
}

//END STRUCTOR

void Vector::print()
{
	std::cout << "[";
	for (int i = 0; i < size; i++)
	{
		std::cout << " " << entries[i] << " ";
	}
	std::cout << "]" << std::endl;
	//Prints out the vector
}

void Vector::set(int val, int pos)
{
	if (pos < 0 || pos >= size)
	{
		std::cout << "ERROR: POSITION OR SIZE OUT OF BOUNDS" << std::endl;
	}
	else
	{
		entries[pos] = val;
	}
}