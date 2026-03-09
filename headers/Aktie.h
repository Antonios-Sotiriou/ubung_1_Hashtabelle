#ifndef AKTIE_H
#define AKTIE_H

#include <iostream>
using namespace std;

class Aktie {
private:
	string wkn; //Wertpapierkennnummer
	string name;
	string kuerzel;
	//Kursdaten

public:
	Aktie();
	Aktie(string name, string wkn, string kuerzel);
	~Aktie();
	string getName();
	string getKuerzel();
	string getWkn();
};

#endif // !AKTIE_H
