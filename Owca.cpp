#include "Owca.h"

Owca::Owca(Swiat* swiat, int x, int y) : Zwierze(swiat, 4, 4, x, y) {};

Owca::~Owca() {};

void Owca::rysowanie() {
	cout << "O" << " ";
}

string Owca::nazwa() {
	return "Owca";
}

Organizm* Owca::dziecko(int x, int y) {
	return new Owca(swiat, x, y);
}