//Tecumseh McMullin CSC275.
//This is the header file for all of the classes for the multithreading.cpp file.
#ifndef CLASSES_H //This is checking to see if classes.h is defined.
#define CLASSES_H //This is defining classes.h if it isn't.

#include <iostream> //This is including the iostream library for basic inputs and outputs.
#include <string> //This is including the string library for the use of strings as inputs.
#include <thread> //This is including the thread library for the use of multithreading.
#include <memory> //This is including the memory library for the use of smart pointers.
#include <chrono> //This is including the chrono library for the use of seconds and ms.

using namespace std; //This is telling the program that I am using the std namespace so I don't have to type std:: all the time.

//This is the rockets class which holds all of the rockets and rocket ids.
class Rockets
{
	//This is the public section holding the contructor, deconstructor and methods.
public:
	//This is the constructor for Rockets.
	Rockets(int ID);
	//This is the deconstructor for Rockets.
	~Rockets();
	//This is the launch() method for Rockets.
	void launch();

	//This is the private section holding all of the variables for the Rockets.
private:
	//Rocket variables.
	int RID;
};





#endif // !CLASSES_H

