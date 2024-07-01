#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, int x, int y) : Roslina(swiat, 10, 0, x, y){}

BarszczSosnowskiego::~BarszczSosnowskiego() {};

void BarszczSosnowskiego::rysowanie() {
	cout << "#" << " ";
}

string BarszczSosnowskiego::nazwa() {
	return "Barszcz_Sosnowskiego";
}

void BarszczSosnowskiego::akcja() {
	Roslina::akcja();
	
	zabij(swiat->getOrganizm(pozycja.x - 1, pozycja.y));
	zabij(swiat->getOrganizm(pozycja.x, pozycja.y - 1));
	zabij(swiat->getOrganizm(pozycja.x + 1, pozycja.y));
	zabij(swiat->getOrganizm(pozycja.x, pozycja.y + 1));
}

void BarszczSosnowskiego::kolizja(Organizm* inny) {
	Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(inny);
	if (czlowiek && czlowiek->czyAktywnaUmiejetnosc()) {
		czlowiek->kolizja(this);
		return;
	}
	else {
		swiat->event(inny->nazwa() + " zjadl " + this->nazwa() + " i ginie");
		swiat->usunOrganizm(inny);
	}
	swiat->usunOrganizm(this);
}

Organizm* BarszczSosnowskiego::dziecko(int x, int y) {
	return new BarszczSosnowskiego(swiat, x, y);
}

void BarszczSosnowskiego::zabij(Organizm* organizm) {
	Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizm);
	if (czlowiek && czlowiek->czyAktywnaUmiejetnosc()) {
		swiat->event(czlowiek->nazwa() + " nie zostal wyeliminowany dzieki trwajacej umiejetnosci"); 
		return; 
	}
	if (dynamic_cast<Zwierze*>(organizm) && organizm != nullptr) {
		swiat->event(this->nazwa() + " eliminuje " + organizm->nazwa());
		swiat->usunOrganizm(organizm);
	}
}