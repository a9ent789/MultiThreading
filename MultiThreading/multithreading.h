//Tecumseh McMullin CSC275.
//This is th header file for the multithreading.cpp.
#ifndef MULTITHREADING_H //This is checking to see if multithreading.h is defined.
#define MULTITHREADING_H //This is defining multithreading.h if it isn't defined.

#include <iostream> //This is including the iostream library for basic inputs and outputs.
#include <string> //This is including the string library for the use of strings as inputs.
#include <thread> //This is including the thread library for the use of multithreading.
#include <memory> //This is including the memory library for the use of smart pointers.
#include <chrono> //This is including the chrono library for the use of seconds and ms.

using namespace std; //This is telling the program that I am using the std namespace so I don't have to type std:: all the time.

//Declaring functions from the functions.cpp file.
void rocketCreator(int rocketID);
void timer(int time);
void rocketPad();

#endif // !MULTITHREADING_H

