#ifndef AKTIE_H
#define AKTIE_H

#include <iostream>
using namespace std;

#include "headers/structs.h"

class Aktie {

	public:
		Aktie();
		Aktie(string name, string wkn, string kuerzel);
		~Aktie();
		string getName();
		void setName(const string newName);
		string getKuerzel();
		void setKuerzel(const string newKuerzel);
		string getWkn();
		void setWkn(const string newWkn);

		AktieData *aktData;

		string wkn; //Wertpapierkennnummer
		string name;
		string kuerzel;
		//Kursdaten
	private:
};

#endif // !AKTIE_H
