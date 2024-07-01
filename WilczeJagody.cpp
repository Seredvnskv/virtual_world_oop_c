#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat* swiat, int x, int y) : Roslina(swiat, 99, 0, x, y) {}

WilczeJagody::~WilczeJagody() {};

void WilczeJagody::rysowanie() {
	cout << "-" << " ";
}

string WilczeJagody::nazwa() {
	return "Wilcze_Jagody";
}

void WilczeJagody::kolizja(Organizm* inny) {
	Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(inny);
	if (czlowiek && czlowiek->czyAktywnaUmiejetnosc()) {
		czlowiek->kolizja(this);
		return;
	}
	else {
		swiat->event(inny->nazwa() + " zjadl " + this->nazwa() + " i ginie");
		swiat->usunOrganizm(inny);
		swiat->usunOrganizm(this);
	}
}

Organizm* WilczeJagody::dziecko(int x, int y) {
	return new WilczeJagody(swiat, x, y);
}