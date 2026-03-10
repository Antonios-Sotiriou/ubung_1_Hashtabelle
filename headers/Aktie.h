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
		bool isEmpty();


		string wkn;         //Wertpapierkennnummer
		string name;
		string kuerzel;
		AktieData *aktData; //Kursdaten

	
		void freeAktData(void);

	private:
};

#endif // !AKTIE_H
