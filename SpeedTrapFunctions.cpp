// SpeedTrapFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// April Laird - Chapter 6 Project

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Global constant
const double baseFine = 60.25;

// Function prototypes
int getSpeedLimit();
int mphOverLimit(int speed, int speedLimit);
void getFine(int overLimit);
char againPrompt(char again);

int main() {
	srand(time(0));
	char again = 'y';
	int overLimit;

	// Loops until user presses key other than 'y'
	while (tolower(again) == 'y') {

		// Call function to generate random speed, store in variable
		int speedLimit = getSpeedLimit();
		// Print the speed limit
		cout << "The speed limit is: " << speedLimit;
		// Prompt for input, store in variable
		cout << "\nEnter the speed: " << endl;
		int speed;
		cin >> speed;
		
		// Call function to calculate fine
		getFine(mphOverLimit(speed, speedLimit));
		// Call function to prompt user to repeat
		again = againPrompt(again);
	}
	// Program ends when key other than 'y' is pressed at prompt
	cout << "Thank you for using the program.";
}

//Function calculates miles over speeding limit
int mphOverLimit(int speed, int speedLimit) {
	int overLimit = speed - speedLimit;
	return overLimit;
}

// Function generates random speed limit between 25 & 65
int getSpeedLimit() {
	int range = 66 - 25;
	return rand() % range + 25;
}

// Function prompts for user input to control while loop
char againPrompt(char again) {
	cout << "\nDo you want to enter another potential speeding violation? Y for yes, any other key for no: ";
	cin >> again;
	return again;		
	}

// Function calculates fine based on mph over limit
void getFine(int overLimit) {

	if (overLimit >= 20) {
		printf("The fine is $%.2f", baseFine * 1.2);
	}

	else if (overLimit > 10) {
		printf("The fine is $%.2f", baseFine * 1.1);
	}

	else if (overLimit > 5) {
		printf("The fine is $%.2f", baseFine * 1.05);
	}

	else if (overLimit <= 5 && overLimit > 0) {
		printf("The fine is $%.2f", baseFine);
	}

	else {
		cout << "You weren't speeding!";
	}
}
