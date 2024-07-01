#include "Zwierze.h"
#include "Czlowiek.h"

Zwierze::Zwierze(Swiat* swiat, int sila, int inicjatywa, int x, int y)
	: Organizm(swiat, sila, inicjatywa, x, y) {
	staraPozycja.x = 0;
	staraPozycja.y = 0;
};

void Zwierze::akcja() {
	staraPozycja.x = pozycja.x; 
	staraPozycja.y = pozycja.y;

	int kierunek = randomRuch();

	if (kierunek != -1) {
		aktualizacjaPozycji(kierunek, pozycja.x, pozycja.y);
	}

	this->dodajWiek();

	swiat->event(this->nazwa() + ", wiek " + to_string(this->getWiek()) + ", ruch z (" + to_string(staraPozycja.x) 
		+ "," + to_string(staraPozycja.y) + ") na (" + to_string(pozycja.x)+ "," + to_string(pozycja.y) + ")");
}

void Zwierze::kolizja(Organizm* inny) {
	Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(inny);
    if (this == inny) return;
    if ((typeid(*this) == typeid(*inny)) && (this->getWiek() > 5 && inny->getWiek() > 5)) {
		inny->cofnijOrganizm();
		this->cofnijOrganizm();

		int pozycjaX = this->pozycja.x;
		int pozycjaY = this->pozycja.y;

		int kierunek = swiat->znajdzPole(pozycja.x, pozycja.y);
		if (kierunek != -1) {
			swiat->dodajOrganizm(dziecko(pozycjaX, pozycjaY));
			swiat->event("Dziecko " + this->nazwa() + " urodzilo sie na pozycji (" + to_string(pozycjaX) + "," + to_string(pozycjaY) + ")");
			return;
		}
		else {
			swiat->event("Brak miejsca na potomka"); 
			return;
		}
	}
	else if (czlowiek && czlowiek->czyAktywnaUmiejetnosc()) {
		czlowiek->kolizja(this);
		return;
	}
    else if (this->getSila() > inny->getSila()) {
		swiat->event(this->nazwa() + " eliminuje " + inny->nazwa());
		swiat->usunOrganizm(inny);
    }
	else if (this->getSila() < inny->getSila()) {
		swiat->event(inny->nazwa() + " eliminuje " + this->nazwa());
		swiat->usunOrganizm(this);
	}
	else if (this->getSila() == inny->getSila() && (typeid(*this) != typeid(*inny))) {
		swiat->event(this->nazwa() + " eliminuje " + inny->nazwa());
		swiat->usunOrganizm(inny);
	}
}

void Zwierze::cofnijOrganizm() {
	pozycja.x = staraPozycja.x;
	pozycja.y = staraPozycja.y;
}

int Zwierze::randomRuch() {
	vector<int> kierunek;

	if (pozycja.y > 0) {
		kierunek.push_back(0);
	}
	if (pozycja.x < swiat->getSzerokosc() - 1) {
		kierunek.push_back(1);
	}
	if (pozycja.y < swiat->getWysokosc() - 1) {
		kierunek.push_back(2);
	}
	if (pozycja.x > 0) {
		kierunek.push_back(3);
	}

	if (kierunek.empty()) {
		return -1;
	}

	return kierunek[rand() % kierunek.size()];
}