#include <iostream>
#include "headers/menu.h"

void displayMenu(void) {
	using namespace std;
	
	cout << "\x1b[H";
	//cout << "\x1b[0;40H";
	//cout << "\x1b[H\x1b[J"; // Erase from current cursor position until the end of the screen.
	//cout << "\x1b[2J";      // Erase entire screen and move cursor to home position (0, 0).
	cout << "\x1b[1J";      // Erase from the start of the screen until cursor position.
	//cout << "\x1b[K";       //  or \x1b[0K . Erase from the current cursor position to the end of the line.
	//cout << "\x1b[1K";      // Erase from the start of the line to the cursor position.
	//cout << "\x1b[2K";      //Erase the entire line.

	cout << "       \x1b[33m\x1b[4mAvailable Aktien\x1b[0m\x1b[0m " << endl;
	cout << "| Nr | Kuerzel | Name      | WKN    |" << endl;
	cout << "|-----------------------------------| " << endl;
	cout << "| 1  | AAPL    | APPLE     | 865985 |" << endl;
	cout << "| 2  | AMD     | AMD       | 863186 |" << endl;
	cout << "| 3  | AMZN    | AMAZON    | 906866 |" << endl;
	cout << "| 4  | CSCO    | CISCO     | 878841 |" << endl;
	cout << "| 5  | META    | META      | A1JWVX |" << endl;
	cout << "| 6  | MSFT    | MICROSOFT | 870747 |" << endl;
	cout << "| 7  | QCOM    | QUALCOMM  | 883121 |" << endl;
	cout << "| 8  | TSLA    | TESLA     | A1CX3T |" << endl;
	cout << " ----------------------------------- " << endl;

	cout << " _________________ " << endl;
	cout << "|    1. ADD       |" << endl;
	cout << "|    2. DEL       |" << endl;
	cout << "|    3. IMPORT    |" << endl;
	cout << "|    4. SEARCH    |" << endl;
	cout << "|    5. PLOT      |" << endl;
	cout << "|    6. SAVE      |" << endl;
	cout << "|    7. LOAD      |" << endl;
	cout << "|    8. QUIT      |" << endl;
	cout << " ----------------- " << endl;
	cout << " Choose an Option[1-8]: " << CURSOR_HOME <<"24H\x1b[K";
}