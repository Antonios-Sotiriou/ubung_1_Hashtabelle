#include <iostream>
#include <string>
#include "headers/menu.h"

int verifyInput(std::string &input);
void dispatchInput(int input);
void clearScreen(void);
void logError(const char error[]);
void logInfo(const char error[]);

int main(int argc, char argv[]) {
	using namespace std;

	string input;
	while (1) {

		displayMenu();
		cin >> input;
		int option = verifyInput(input);
		if (option == 8) {
			break;
		} else if (option >= 0) {
		    dispatchInput(option);
		}
	}

	return 0;
}
int verifyInput(std::string &input) {
	clearScreen();
	if (input.length() > 1) {
		logError("Invalid length");
		return -1;
	} else {
		if (input[0] < 48 || input[0] > 57) {
			logError("Not a number");
			return -1;
		}
		return input[0] - 48;
	}
	return 0;
}
void dispatchInput(int input) {
	switch (input) {
		case 1:
			// ADD
			break;
		case 2:
			// DEL
			break;
		case 3:
			// IMPORT
			break;
		case 4:
			// SEARCH
			break;
		case 5:
			// PLOT
			break;
		case 6:
			// SAVE
			break;
		case 7:
			// LOAD
			break;
		default:
			logError("Only numbers between 1 and 8 are valid");
	}
}
void clearScreen(void) {
	std::cout << "\x1b[H\x1b[J";
}
void logError(const char error[]) {
	std::cout << "\x1b[24;0H\x1b[2K\x1b[31m" << error << "\x1b[0m" << std::endl;
}
void logInfo(const char info[]) {
	std::cout << "\x1b[24;0H\x1b[2K\x1b[32m" << info << "\x1b[0m" << std::endl;
}