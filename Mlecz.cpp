#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat, int x, int y) : Roslina(swiat, 0, 0, x, y) {}

Mlecz::~Mlecz() {};

void Mlecz::rysowanie() {
	cout << "*" << " ";
}

string Mlecz::nazwa() {
	return "Mlecz";
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}

void Mlecz::kolizja(Organizm* inny) {
	swiat->event("Zwierze " + inny->nazwa() + " zjadlo " + this->nazwa() + ".");
	swiat->usunOrganizm(this);
}

Organizm* Mlecz::dziecko(int x, int y) {
	return new Mlecz(swiat, x, y);
}