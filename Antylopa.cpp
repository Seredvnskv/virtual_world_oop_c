#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat, int x, int y) : Zwierze(swiat, 4, 4, x, y) {};

Antylopa::~Antylopa() {};

void Antylopa::rysowanie() {
	cout << "A" << " ";
}

string Antylopa::nazwa() {
	return "Antylopa";
}

Organizm* Antylopa::dziecko(int x, int y) {
	return new Antylopa(swiat, x, y);
}

void Antylopa::akcja() {
	staraPozycja.x = pozycja.x;
	staraPozycja.y = pozycja.y;

	int kierunek = randomRuch();

	if (kierunek != -1) {
		ruchAntylopa(kierunek, pozycja.x, pozycja.y);
	}

	this->dodajWiek();

	swiat->event(this->nazwa() + ", wiek " + to_string(this->getWiek()) + ", ruch z (" + to_string(staraPozycja.x)
		+ "," + to_string(staraPozycja.y) + ") na (" + to_string(pozycja.x) + "," + to_string(pozycja.y) + ")");
}

void Antylopa::kolizja(Organizm* inny) {
	bool czyUcieka = rand() % 2; 
	if (czyUcieka) {
		int pozycjaX = pozycja.x;
		int pozcyjaY = pozycja.y;
		int kierunek = swiat->znajdzPole(pozycja.x, pozycja.y);

		if (kierunek != -1) {
			aktualizacjaPozycji(kierunek, pozycjaX, pozcyjaY);
			setPozycja(pozycjaX, pozcyjaY);
			swiat->event(this->nazwa() + " ucieka na pole (" + to_string(pozycjaX) + "," + to_string(pozcyjaY) + ")");
			return;
		}
		else {
			swiat->event(this->nazwa() + " nie moze uciec ale nie ginie.");
			return;
		}
	}
	Zwierze::kolizja(inny);
}

void Antylopa::ruchAntylopa(int kierunek, int& x, int& y) {
	int pozycjaX = x; 
	int pozycjaY = y; 

	switch (kierunek) {
	case 0:
		pozycjaY = y - 2;
		break;
	case 1:
		pozycjaX = x + 2;
		break;
	case 2:
		pozycjaY = y + 2;
		break;
	case 3:
		pozycjaX = x - 2;
		break;
	}

	if (pozycjaX < 0) {
		pozycjaX = 0;
	}
	else if (pozycjaY < 0) {
		pozycjaY = 0;
	}
	else if (pozycjaX >= swiat->getSzerokosc()) {
		pozycjaX = swiat->getSzerokosc() - 1; 
	}
	else if (pozycjaY >= swiat->getWysokosc()) {
		pozycjaY = swiat->getWysokosc() - 1;
	}

	pozycja.x = pozycjaX;
	pozycja.y = pozycjaY;
}