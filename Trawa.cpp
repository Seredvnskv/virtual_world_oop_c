#include "Trawa.h"

Trawa::Trawa(Swiat* swiat, int x, int y) : Roslina(swiat, 0, 0, x, y) {}

Trawa::~Trawa() {};

void Trawa::rysowanie() {
	cout << "." << " ";
}

string Trawa::nazwa() {
	return "Trawa";
}

void Trawa::kolizja(Organizm* inny) {
	swiat->event("Zwierze " + inny->nazwa() + " zjadlo " + this->nazwa() + ".");
	swiat->usunOrganizm(this);
}

Organizm* Trawa::dziecko(int x, int y) {
	return new Trawa(swiat, x, y);
}