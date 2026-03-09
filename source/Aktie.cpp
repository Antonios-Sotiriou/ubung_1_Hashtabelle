#include "headers/Aktie.h"
#include <iostream>
using namespace std;

Aktie::Aktie() {
	this->kuerzel = "";
	this->name = "";
	this->wkn = "";
}

Aktie::Aktie(string name, string wkn, string kuerzel) {
	this->kuerzel = kuerzel;
	this->name = name;
	this->wkn = wkn;
}

Aktie::~Aktie() {
	
}

string Aktie::getName() {
	return kuerzel;
}

string Aktie::getKuerzel() {
	return name;
}

string Aktie::getWkn() {
	return wkn;
}