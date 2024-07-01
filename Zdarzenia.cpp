#include "Zdarzenie.h"

Zdarzenia::Zdarzenia() {};
Zdarzenia::~Zdarzenia() {};

void Zdarzenia::dodaj(const string& zdarzenie) {
	zdarzenia.push_back(zdarzenie);
}

void Zdarzenia::wyswietlZdarzenia() {
	for (const auto& zdarzenie : zdarzenia) {
		cout << zdarzenie << endl;
	}
}

void Zdarzenia::wyczyscZdarzenia() {
	zdarzenia.clear();
}