//Tecumseh McMullin CSC275.
//This is the functions.cpp file for all of the functions for multithreading.cpp.

#include <iostream> //This is including the iostream library for basic inputs and outputs.
#include <string> //This is including the string library for the use of strings as inputs.
#include <thread> //This is including the thread library for the use of multithreading.
#include <memory> //This is including the memory library for the use of smart pointers.
#include <chrono> //This is including the chrono library for the use of seconds and ms.
#include "classes.h" //This is including the classes.h header file.
#include "multithreading.h" //This is including the multithreading.h header file.

using namespace std; //This is telling the program that I am using the std namespace so I don't have to type std:: all the time.

//This is the rocketCreator() function, it is used to create rockets from the Rockets class.
void rocketCreator(int rocketID) {
	//This is an output getting the main thread id.
	cout << "Getting main thread ID:" << this_thread::get_id() << endl;
	//This is a unique pointer creating new rockets, it also deconstructs after the function is ended so I don't have to do it manually.
	unique_ptr<Rockets> rocket(new Rockets(rocketID));
	//This is using the unique pointer to call the launch() method.
	rocket->launch();

	//This sleeps the thread for 1 second allowing time for the user to read.
	this_thread::sleep_for(1000ms);
	
}

//This is the timer() function, its for the launch countdown.
void timer(int time) {
	//Output telling the user when the rocket will launch.
	cout << "Launching in T-" << time << " seconds." << endl;
	
	//This sleeps the thread for 1 second to make the timer accurate.
	this_thread::sleep_for(1000ms);
}

//This is the controlExit() function, it is used in case the user wants to take back control of the rockets and cancel the launch.
void controlExit() {
	//Output to say goodbye and what happened.
	cout << "control has been reclaimed and the rocket launches terminated, goodbye." << endl;

	//This is the exit() function and it exits the program passing 0 to the computer saying that there were no errors.
	exit(0);
}

//This is the rocketPad() function, used to take user input if they want to take back control or let the rockets launch.
void rocketPad() {

	//Declaring local variables.
	string input;

	//Output for looks.
	cout << "" << endl;
	//Output that is prompting the user for the input if they want.
	cout << "Enter \"transfer\" to reclaim control from the space cadet and cancel the rest of the launches." << endl;
	//Output telling the user that they can skip and just continue the launches.
	cout << "Press enter to continue the launches." << endl;

	//This is the getline() function, it is getting the user input and changing input, this allows me to use the string.
	getline(cin, input);

	//This is an if statement checking to see if the user inputed "transfer".
	if (input == "transfer") {
		//This runs the controlExit() function.
		controlExit();
	}
}
