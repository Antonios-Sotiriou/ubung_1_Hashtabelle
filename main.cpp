#include <iostream>
#include <string>
#include "headers/menu.h"

int verifyInput(std::string &input);
int hashFunction(std::string &str);
void dispatchInput(int input);

int main(int argc, char argv[]) {
	using namespace std;

	string input;
	string aktie = "AAPL";

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
	std::cout << "\x1b[H\x1b[J";
	if (input.length() > 1) {
		std::cout << CURSOR_ERROR << "0H\x1b[2K\x1b[31m Invalid length\x1b[0m" << std::endl;
		return -1;
	} else {
		if (input[0] < 48 || input[0] > 57) {
			std::cout << CURSOR_ERROR << "0H\x1b[2K\x1b[31m " << input << " is not a number\x1b[0m" << std::endl;
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
			std::cout << CURSOR_ERROR << "0H\x1b[2K\x1b[31m Only numbers between 1 and 8 are valid\x1b[0m" << std::endl; 
	}
}
void logError(char error[]) {
	std::cout << "\x1b[24;0H\x1b[2K\x1b[31m" << error << "\x1b[0m" << std::endl;
}
void logInfo(char error[]) {
	std::cout << "\x1b[24;0H\x1b[2K\x1b[32m" << error << "\x1b[0m" << std::endl;
}