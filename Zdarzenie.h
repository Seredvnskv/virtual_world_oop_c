#pragma once
#include <list>
#include <string>
#include <iostream>

using namespace std;

class Zdarzenia {
private:
	list<string> zdarzenia;
public:
	Zdarzenia();
	~Zdarzenia();

	void dodaj(const string& zdarzenie); 
	void wyswietlZdarzenia();
	void wyczyscZdarzenia();
};
