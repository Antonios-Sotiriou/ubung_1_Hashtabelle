#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "headers/main.h"
#include "headers/menu.h"
#include "headers/structs.h"

#define AKTIEN_PATH       "C:/Users/anton/Desktop/Bachelor_Informatik/Semester_2/ALGOS/ubung_1_Hashtabelle/aktien/"
#define AKTIE_NAME        "APPLE"
#define NUM_OF_AKTIEN     999

int verifyInput(std::string &input);
void dispatchInput(AktieData *aktData, int input);
void clearScreen(void);
void logError(const char error[]);
void logInfo(const char error[]);
void import(AktieData *aktData, std::string aktie_name, int num_of_aktien);
void initAktie(std::ifstream &file, AktieData &aktie);
void plot(AktieData *aktData, std::string aktie_name, int num_of_aktien);

int main(int argc, char argv[]) {
	using namespace std;

	AktieData *aktData = new AktieData[sizeof(AktieData) * NUM_OF_AKTIEN];  // Hardcoded Value for Aktien. Must be changed!

	string input;
	while (1) {

		//displayMenu();
		cin >> input;
		int option = verifyInput(input);
		if (option == 8) {
			break;
		} else if (option >= 0) {
		    dispatchInput(aktData, option);
		}
	}

	delete[] aktData;
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
void dispatchInput(AktieData *aktData, int input) {
	switch (input) {
		case 1:
			// ADD
			break;
		case 2:
			// DEL
			break;
		case 3:
			// IMPORT
			import(aktData, AKTIE_NAME, NUM_OF_AKTIEN); // Hardcoded Value for Aktien. Must be changed!
			break;
		case 4:
			// SEARCH
			break;
		case 5:
			// PLOT
            plot(aktData, AKTIE_NAME, NUM_OF_AKTIEN); // Hardcoded Value for Aktien. Must be changed!
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
	std::cout << CLEAR_SCREEN;
}
void logError(const char error[]) {
	std::cout << CURSOR_ERROR << "\x1b[2K\x1b[31m" << error << "\x1b[0m" << std::endl;
}
void logInfo(const char info[]) {
	std::cout << CURSOR_INFO << "\x1b[2K\x1b[32m" << info << "\x1b[0m" << std::endl;
}
void import(AktieData *aktData, std::string aktie_name, int num_of_aktien) {
	std::ifstream myReadFile(aktie_name.insert(0, AKTIEN_PATH).append(".csv"));
	if (!myReadFile.is_open()) {
		std::cout << "Could not read file!  " << aktie_name;
		return;
	}

	// Discard the header.
	std::string line;
	getline(myReadFile, line);

	int counter = 0;
	while (counter < num_of_aktien) {
		initAktie(myReadFile, aktData[counter]);
		counter++;
	}

	myReadFile.close();
}
void initAktie(std::ifstream &file, AktieData &aktie) {
	using namespace std;
	string line;
	getline(file, line);

	const char *delimiters = ",$";
	char *context = nullptr;
	char *token = strtok_s((char*)line.c_str(), delimiters, &context);

	aktie.date = token;
	//cout << "  " << aktie.date << " ";

	token = strtok_s(nullptr, delimiters, &context);
	aktie.close = stof(token);
	//cout << aktie.close  << " ";

	token = strtok_s(nullptr, delimiters, &context);
	aktie.volume = stoi(token);
	//cout << aktie.volume << " ";

	token = strtok_s(nullptr, delimiters, &context);
	aktie.open = stof(token);
	//cout << aktie.open << " ";

	token = strtok_s(nullptr, delimiters, &context);
	aktie.high = stof(token);
	//cout << aktie.high << " ";

	token = strtok_s(nullptr, delimiters, &context);
	aktie.low = stof(token);
	//cout << aktie.low << endl;
}
void plot(AktieData *aktData, std::string aktie_name, int num_of_aktien) {
	clearScreen();
	std::cout << CURSOR_HOME;

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	int move_left = 0;
	float previous_price = ~(1 << 31);
	for (int i = 29; i >= 0; i--) {
		std::cout << aktData[i].close << "|";
		std::cout << "\x1b[" << 88 - move_left << "C*" << std::endl;

		//if (previous_price < aktData[i].close) {
		//	std::cout << "\x1b[" << 30 - move_left << "C\\" << std::endl;
		//} else if (previous_price > aktData[i].close) {
		//	std::cout << "\x1b[" << 30 - move_left << "C/" << std::endl;
		//} else {
		//	std::cout << "\x1b[" << 30 - move_left << "C-" << std::endl;
		//}

		previous_price = aktData[i].close;
		move_left += 3;
	}

	std::cout << "\x1b[30;0HDay    ";
	for (int i = 29; i >= 0; i--) {
		std::cout << aktData[i].date.substr(3, 2) << "|";
	}

	getchar();
	getchar();
}