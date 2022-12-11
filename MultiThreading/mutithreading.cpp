//Tecumseh McMullin CSC275.
//This is the main .cpp file for the multithreading application.
//This program is supposed to launch rockets using multithreading.

#include <iostream> //This is including the iostream library for basic inputs and outputs.
#include <string> //This is including the string library for the use of strings as inputs.
#include <thread> //This is including the thread library for the use of multithreading.
#include <memory> //This is including the memory library for the use of smart pointers.
#include <chrono> //This is including the chrono library for the use of seconds and ms.
#include "classes.h" //This is including the classes.h header file.
#include "multithreading.h" //This is including the multithreading.h header file.

using namespace std; //This is telling the program that I am using the std namespace so I don't have to type std:: all the time.


//This is the main() function without it the program won't run and it controls everything else.
int main() {
	//This is title screen output.
	cout << "Welcome to the rocket launch command!" << endl;
	//This is telling the user that main base will launch the first rocket.
	cout << "main base will launch rocket number 1 then transfer control to the rocket pad space cadet." << endl;
	//This is prompting the user to hit enter to continue the program.
	cout << "currently at main base please press enter to start launching the 10 rockets." << endl;
	//This is checking to see if the user hit enter.
	cin.get();
	
	//This is a for loop that will run 10 times to launch 10 rockets.
	for (int i = 0;i < 10; i++) {
		//This is delcaring a local variable that is used for the RID.
		int rocketID = i + 1;
		//This is an if statement that checks to see if this is the first time it has been run.
		if (i == 0) {
			//This is output for looks.
			cout << "" << endl;
			//This is telling the user that the rocket is being launched from the main base.
			cout << "*** Launching rocket from main base ***" << endl;
			//This is output for looks.
			cout << "" << endl;
		}
		//This is a thread created to run the function rocketCreator() and passes in rocketID to the function.
		thread rocketLauncher(rocketCreator,rocketID);
		//This joins the thread so that no errors pop up.
		rocketLauncher.join();
		//This is a for loop used for the timer, it will run 3 times.
		for (int t = 3;t > 0; t--) {
			//This is a thread that runs the function timer() and passes in t for the time to the function.
			thread tMinus(timer, t);
			//This joins the thread so that no errors pop up.
			tMinus.join();
		}
		//This is an if statement checking to see if this was the first time it ran.
		if (i == 0) {
			//This is output for looks.
			cout << "" << endl;
			//This is telling the user that the control is being transfered to the rocket pad space cadet.
			cout << "*** Transferring control to rocket pad space cadet. ***" << endl;
		}
		//This is an if statement checking to se if it has ran at all.
		if (i >= 0) {
			//This is a thread the runs the function rocketPad.
			thread control(rocketPad);
			//This joins the thread so that no errors pop up.
			control.join();
			//This is output for looks.
			cout << "" << endl;
			//This is telling the user that the rocket is launching from the rocket pad.
			cout << "*** Launching rocket from rocket pad ***" << endl;
			//This is output for looks.
			cout << "" << endl;
		}
	}
	//This is output telling the user that all the launches were completed and then tells them goodbye.
	cout << "All rocket launches completed, goodbye." << endl;

	//This returns 0 to the computer saying that there were no errors.
	return 0;
}