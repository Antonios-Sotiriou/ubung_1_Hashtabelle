#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "headers/main.h"
#include "headers/menu.h"
#include "headers/structs.h"
#include "headers/Aktie.h"

#define DATABASE_PATH     "C:/Users/anton/Desktop/Bachelor_Informatik/Semester_2/ALGOS/ubung_1_Hashtabelle/database/"
#define AKTIEN_PATH       "C:/Users/anton/Desktop/Bachelor_Informatik/Semester_2/ALGOS/ubung_1_Hashtabelle/aktien/"
#define AMAZON            "AMAZON"
#define AMD               "AMD"
#define APPLE             "APPLE"
#define CISCO             "CISCO"
#define META              "META"
#define MICROSOFT         "MICROSOFT"
#define QUALCOMM          "QUALCOMM"
#define TESLA             "TESLA"

#define NUM_OF_AKTIEN     999
#define HASH_TABLE_SIZE   1301

int hashFunction(Aktie* aktien,std::string &str, const int hash_table_size, int search_flag);
int verifyInput(std::string& input);
void dispatchInput(Aktie *aktData, int input);
void setTerminalSize(const int rows, const int columns);
void clearScreen(void);
void logError(const char error[]);
void logInfo(const char error[]);
void clearLogs(void);
void add(Aktie* aktien);
void import(Aktie *aktien, int num_of_aktien);
void search(Aktie* aktien);
void initAktie(std::ifstream &file, AktieData *aktieData);
void plot(Aktie *aktien, int num_of_aktien);
void sortFloatArray(float arr[], const int array_length);
void save(Aktie* aktien, const int hash_table_size);
void load(Aktie *aktien, const int hash_table_size);
int collisionFunction(Aktie* aktieArray, std::string& str, int index, int search_flag);

int main(int argc, char argv[]) {
	using namespace std;

	//AktieData *aktData = new AktieData[sizeof(AktieData) * NUM_OF_AKTIEN];  // Hardcoded Value for Aktien. Must be changed!
	Aktie *aktien = new Aktie[sizeof(Aktie) * HASH_TABLE_SIZE];
	aktien[633] = Aktie("AMAZON", "AMZN", "906866");

	setTerminalSize(31, 120);

	string input;
	while (1) {

		displayMenu();
		cin >> input;
		int option = verifyInput(input);
		if (option == 8) {
			break;
		} else if (option >= 0) {
		    dispatchInput(aktien, option);
		}
	}

	delete[] aktien;

	return 0;
}
int hashFunction(Aktie* aktieArray,std::string& str, const int hash_table_size,int search_flag) {
	int hash = 0;
	int length = 4;

	if (str.length() < 4) {
		length = static_cast<int>(str.length());
	}

	for (int i = 0; i < length; i++) {
		hash += str[i] * static_cast<int>(std::pow(31, length - (i + 1)));
	}

	return collisionFunction(aktieArray,str,hash % hash_table_size,search_flag);
}
int collisionFunction(Aktie* aktieArray,std::string& str,int index,int search_flag) {
	string compare = "";
	if (search_flag == 1) {
		compare = str;
	}

	if (aktieArray[index].getKuerzel() == compare) {
		return index;
	}
	int offset = 1;
	int negation = 1;
	while (!(aktieArray[index + (negation * offset * offset)].getKuerzel() == compare)) {
		if (negation < 0) {
			negation *= -1;
			offset *= 2;
		}
		else
		{
			negation *= -1;
		}
	}
	return index + (negation * offset * offset);
}
int verifyInput(std::string &input) {

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
void dispatchInput(Aktie *aktien, int input) {
	switch (input) {
		case 1:
			add(aktien);
			break;
		case 2:
			// DEL
			break;
		case 3:
			import(aktien, NUM_OF_AKTIEN); // Hardcoded Value for Aktien. Must be changed!
			break;
		case 4:
			search(aktien); // only kurzel search implemented
			break;
		case 5:
            plot(aktien, NUM_OF_AKTIEN); // Hardcoded Value for Aktien. Must be changed!
			break;
		case 6:
			save(aktien, HASH_TABLE_SIZE);
			break;
		case 7:
			load(aktien, HASH_TABLE_SIZE);
			break;
		default:
			logError("Only numbers between 1 and 8 are valid");
	}
}
void setTerminalSize(const int rows, const int columns) {
	std::cout << "\x1b[8;" << rows << ";" << columns << "t";
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
void clearLogs(void) {
	std::cout << CURSOR_ERROR << "\x1b[2K\x1b[0m" << std::endl;
	std::cout << CURSOR_INFO << "\x1b[2K\x1b[0m" << std::endl;
}
void add(Aktie* aktien) {
	string name;
	string wkn;
	string kuerzel;
	std::cout << "Give name of Aktie: ";
	std::cin >> name;
	std::cout << "Give kurzel of Aktie: ";
	std::cin >> kuerzel;
	std::cout << "Give wkn of Aktie: ";
	std::cin >> wkn;
	Aktie newAktie(name,wkn,kuerzel);
	aktien[hashFunction(aktien, kuerzel, HASH_TABLE_SIZE,0)] = newAktie;
}
void import(Aktie *aktien, int num_of_aktien) {
	clearLogs();
	std::cout << "\x1b[23;0H\x1b[2K\x1b[32mName of Aktie to import: \x1b[23;26H\x1b[0m";
	string name;
	std::cin >> name;

	int aktie_index = hashFunction(name, HASH_TABLE_SIZE);
	if (aktien[aktie_index].aktData == nullptr) {
	    aktien[aktie_index].aktData = new AktieData[sizeof(AktieData) * num_of_aktien];
	}

	std::ifstream myReadFile(aktien[aktie_index].name.insert(0, AKTIEN_PATH).append(".csv"));

	if (!myReadFile.is_open()) {
		std::cout << CURSOR_INFO << "\x1b[2K\x1b[31m" << "Could not found aktie file with name: " << name << "\x1b[0m" << std::endl;
		return;
	}

	// Discard the header.
	std::string line;
	getline(myReadFile, line);

	int counter = 0;
	while (counter < num_of_aktien) {       // O(n)
		initAktie(myReadFile, &aktien[aktie_index].aktData[counter]); // O(1)
		counter++;
	}
	
	myReadFile.close();
}
void initAktie(std::ifstream &file, AktieData *aktieData) {
	using namespace std;
	string line;
	getline(file, line);

	const char *delimiters = ",$";
	char *context = nullptr;
	char *token = strtok_s((char*)line.c_str(), delimiters, &context);

	aktieData->date = token;

	token = strtok_s(nullptr, delimiters, &context);
	aktieData->close = stof(token);

	token = strtok_s(nullptr, delimiters, &context);
	aktieData->volume = stoi(token);

	token = strtok_s(nullptr, delimiters, &context);
	aktieData->open = stof(token);

	token = strtok_s(nullptr, delimiters, &context);
	aktieData->high = stof(token);

	token = strtok_s(nullptr, delimiters, &context);
	aktieData->low = stof(token);
}
void search(Aktie* aktien) {
	string name;
	std::cout << "give aktie name";
	cin >> name;

	Aktie result = aktien[hashFunction(aktien, name, HASH_TABLE_SIZE, 1)];
}
void plot(Aktie *aktien, int num_of_aktien) {

	std::cout << "\x1b[23;0H\x1b[2K\x1b[32mName of Aktie to Plot: \x1b[23;24H\x1b[0m";
	std::cout << "\x1b[0J";
	string name;
	std::cin >> name;

	clearScreen();
	std::cout << CURSOR_HOME;

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	int aktie_index = hashFunction(name, HASH_TABLE_SIZE);
	if (aktien[aktie_index].aktData == nullptr) {
		logError("Aktie not found!");
		return;
	}

	float sorted_prices[30];
	for (int i = 29; i >= 0; i--) {                   // O(n)
		sorted_prices[i] = aktien[aktie_index].aktData[i].close;
	}
	sortFloatArray(sorted_prices, 30);                // O(n^2)

	int move_left = 0;
	for (int i = 29; i >= 0; i--) {
		std::cout << sorted_prices[i] << "|";

		std::cout << "\x1b[" << 88 - move_left << "C" << std::endl;

		move_left += 3;
	}

	int cursor_left = 8;
	std::cout << "\x1b[31;0HDay   |";
	for (int i = 29; i >= 0; i--) {                   // O(n^2)
		std::cout << "\x1b[31;" << cursor_left << "H" << aktien[aktie_index].aktData[i].date.substr(3, 2) << "|";

		int prices_index = 0;
		while ((aktien[aktie_index].aktData[i].close >= sorted_prices[prices_index]) && (prices_index < 30)) {
			std::cout << "\x1b[" << 30 - prices_index << ";" << cursor_left << "H*";
			std::cout << "\x1b[" << 30 - prices_index << ";" << cursor_left + 1 << "H*";
			//std::cout << "\x1b[" << 29 - prices_index << ";" << cursor_left + 2 << "H*";
			prices_index++;
		}

		cursor_left += 3;
	}
	std::cout << "\x1b[31;99H\x1b[?25l\x1b[8m";

	getchar();
	getchar();
	system("cls");
}
void sortFloatArray(float arr[], const int array_length) {

	for (int x = 0; x < array_length; x++) {
		for (int y = 0; y < array_length; y++) {           // O(n) * O(n) = O(n^2)
			if (arr[x] < arr[y]) {
				float temp = arr[x];
				arr[x] = arr[y];
				arr[y] = temp;
			}
		}
	}
}
void save(Aktie *aktien, const int hash_table_size) {
	std::cout << "\x1b[23;0H\x1b[2K\x1b[31mFilenname to save hash table into: \x1b[0m";
	string filename;
	std::cin >> filename;

    std::fstream file(filename.insert(0, DATABASE_PATH), std::ios::out | std::ios::in | std::ios::trunc);

	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		file.write(aktien[i].getName().c_str(), aktien[i].getName().length());
		file.write(aktien[i].getKuerzel().c_str(), aktien[i].getKuerzel().length());
		file.write(aktien[i].getWkn().c_str(), aktien[i].getWkn().length());
	}

	file.close();
}
void load(Aktie *aktien, const int hash_table_size) {
	std::cout << "\x1b[23;0H\x1b[2K\x1b[32mFilename to load hash table from: \x1b[0m";
	string filename;
	std::cin >> filename;

    std::fstream file(filename.insert(0, DATABASE_PATH));
	if (!file.is_open()) {
		std::cout << CURSOR_INFO << "\x1b[2K\x1b[31m" << "Could not read file: " << filename << "\x1b[0m" << std::endl;
		return;
	}

	for (int i = 0; i < hash_table_size; i++) {
		file >> aktien[i].name;
		file >> aktien[i].kuerzel;
		file >> aktien[i].wkn;
	}

	file.close();
}