#include "headers/Aktie.h"
#include <iostream>
using namespace std;

Aktie::Aktie() {
	this->kuerzel = "";
	this->name = "";
	this->wkn = "";
	this->aktData = nullptr;
}

Aktie::Aktie(string name,  string kuerzel, string wkn) {
	this->kuerzel = kuerzel;
	this->name = name;
	this->wkn = wkn;
	this->aktData = nullptr;
}

Aktie::~Aktie() {
	freeAktData();
}

string Aktie::getName() {
	return name;
}

void Aktie::setName(const string newName) {
	name = newName;
}

string Aktie::getKuerzel() {
	return kuerzel;
}

void Aktie::setKuerzel(const string newKuerzel) {
	kuerzel = newKuerzel;
}

string Aktie::getWkn() {
	return wkn;
}

void Aktie::setWkn(const string newWkn) {
	wkn = newWkn;
}

bool Aktie::isEmpty() {
	return name.empty();
}

void Aktie::freeAktData(void) {
	if (aktData != nullptr) {
		delete aktData;
		aktData = nullptr;
	}
}