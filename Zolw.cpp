#include "Zolw.h" 

Zolw::Zolw(Swiat* swiat, int x, int y) : Zwierze(swiat, 2, 1, x, y) {};

Zolw::~Zolw() {};

void Zolw::rysowanie() {
	cout << "Z" << " ";
}

string Zolw::nazwa() {
	return "Zolw";
}

Organizm* Zolw::dziecko(int x, int y) {
	return new Zolw(swiat, x, y);
}

void Zolw::akcja() {
	int random = rand() % 4; 
	if (!random) {
		Zwierze::akcja();
	}
}

void Zolw::kolizja(Organizm* inny) {
	if (inny->getSila() < 5 && (typeid(*this) != typeid(*inny))) {
		inny->cofnijOrganizm();
		swiat->event(this->nazwa() + " broni sie przed atakiem " + inny->nazwa());
	}
	else {
		Zwierze::kolizja(inny);
	}
}