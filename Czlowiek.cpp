#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat* swiat, int x, int y) : Zwierze(swiat, 5, 4, x, y) {
	this->pozostaleTury = 0;
	this->turyTrwania = 0;
	this->aktywnaUmiejetnosc = false;
};

Czlowiek::~Czlowiek() {};

void Czlowiek::aktywujUmiejetnosc() {
	if (aktywnaUmiejetnosc) {
		swiat->event("Umiejetnosc niesmiertelnosc jest juz aktywna i bedzie trwac nastepujaca liczbe tur: " + to_string(turyTrwania));
	}
	else if (pozostaleTury > 0) {
		swiat->event("Umiejetnosc niesmiertelnosc bedzie dostepna za nastepujaca liczbe tur: " + to_string(pozostaleTury));
	}
	else {
		aktywnaUmiejetnosc = true;
		turyTrwania = 5;
		pozostaleTury = 10;
		swiat->event(this->nazwa() + " aktywuje umiejetnosc niesmiertelnosc.");
	}
}

void Czlowiek::akcja(int kierunek) {
	staraPozycja.x = pozycja.x;
	staraPozycja.y = pozycja.y;

	aktualizacjaCzlowieka(kierunek, pozycja.x, pozycja.y);

	if (aktywnaUmiejetnosc) {
		turyTrwania--;
		if (turyTrwania == 0) {
			aktywnaUmiejetnosc = false;
			swiat->event("Umiejetnosc niesmiertelnosc czlowieka sie zakonczyla");
		}
	}

	if (pozostaleTury > 0) {
		pozostaleTury--;
	}

	this->dodajWiek();

	swiat->event(this->nazwa() + ", wiek " + to_string(this->getWiek()) + ", ruch z (" + to_string(staraPozycja.x)
		+ "," + to_string(staraPozycja.y) + ") na (" + to_string(pozycja.x) + "," + to_string(pozycja.y) + ")");
}

void Czlowiek::kolizja(Organizm* inny) {
	if (aktywnaUmiejetnosc && (this->getSila() < inny->getSila())) {
		int pozycjaX = pozycja.x;
		int pozcyjaY = pozycja.y;
		int kierunek = swiat->znajdzPole(pozycja.x, pozycja.y);

		if (kierunek != -1) {
			aktualizacjaPozycji(kierunek, pozycjaX, pozcyjaY);
			setPozycja(pozycjaX, pozcyjaY);
			swiat->event(this->nazwa() + " ucieka na pole (" + to_string(pozycjaX) + "," + to_string(pozcyjaY) + ")");
			return;
		}
		else if (kierunek == -1) {
			swiat->event(this->nazwa() + " nie moze uciec ale nie ginie.");
			return;
		}
	}
	Zwierze::kolizja(inny);
}

void Czlowiek::rysowanie() {
	cout << "C" << " ";
}

string Czlowiek::nazwa() {
	return "Czlowiek";
}

Organizm* Czlowiek::dziecko(int x, int y) {
	return nullptr;
}

bool Czlowiek::czyAktywnaUmiejetnosc() {
	return aktywnaUmiejetnosc;
}

int Czlowiek::getPozostaleTury() {
	return pozostaleTury;
}

int Czlowiek::getTuryTrwania() {
	return turyTrwania;
}

void Czlowiek::ustawStanUmiejetnosci(bool aktywna, int pozostaleTury, int turyTrwania) {
	this->aktywnaUmiejetnosc = aktywna;
	this->pozostaleTury = pozostaleTury;
	this->turyTrwania = turyTrwania;
}