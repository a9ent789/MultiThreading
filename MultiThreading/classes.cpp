//Tecumseh McMullin CSC275.
//This is the cpp file for all of the classes for multithreading.cpp.

#include <iostream> //This is including the iostream library for basic inputs and outputs.
#include <string> //This is including the string library for the use of strings as inputs.
#include <thread> //This is including the thread library for the use of multithreading.
#include <memory> //This is including the memory library for the use of smart pointers.
#include <chrono> //This is including the chrono library for the use of seconds and ms.
#include "classes.h" //This is including the classes.h header file.
#include "multithreading.h" //This is including the multithreading.h header file.

using namespace std; //This is telling the program that I am using the std namespace so I don't have to type std:: all the time.

//This is the constructor method for Rockets and it passes in an int.
Rockets::Rockets(int ID)
{
	//This changes the RocketID to the integer passed in.
	RID = ID;
}

//This is the deconstructor method for Rockets.
Rockets::~Rockets()
{
}

//This is the launch() method for rockets and outputs that the rocket is launching.
void Rockets::launch()
{
	//The output with the use of the Rocket ID.
	cout << "Launching rocket number " << RID << endl;
}

