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
	//if (aktData != nullptr)
	//    delete[] aktData;
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