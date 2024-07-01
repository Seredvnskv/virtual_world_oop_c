#include "Guarana.h"

Guarana::Guarana(Swiat* swiat, int x, int y) : Roslina(swiat, 0, 0, x, y) {}

Guarana::~Guarana() {};

void Guarana::kolizja(Organizm* inny) {
	inny->dodajSile(3);
	swiat->event("Zwierze " + inny->nazwa() + " zjadlo " + this->nazwa() + " aktualna sila " + to_string(inny->getSila()));
	swiat->usunOrganizm(this);
}

Organizm* Guarana::dziecko(int x, int y) {
	return new Guarana(swiat, x, y);
}

void Guarana::rysowanie() {
	cout << "+" << " ";
}

string Guarana::nazwa() {
	return "Guarana";
}