#include "Wilk.h"

Wilk::Wilk(Swiat* swiat, int x, int y) : Zwierze(swiat, 9, 5, x, y) {};

Wilk::~Wilk() {};

void Wilk::rysowanie() {
	cout << "W" << " ";
}

string Wilk::nazwa() {
	return "Wilk";
}

Organizm* Wilk::dziecko(int x, int y) {
	return new Wilk(swiat, x, y); 
}