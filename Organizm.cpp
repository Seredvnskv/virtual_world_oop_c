#include "Organizm.h"

Organizm::Organizm(Swiat* swiat, int sila, int inicjatywa, int x, int y) : swiat(swiat), sila(sila), inicjatywa(inicjatywa), wiek(0), pozycja({x, y}){}

Organizm::~Organizm() {};

int Organizm::getSila()
{
	return sila;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

int Organizm::getWiek() {
	return wiek;
}

int Organizm::getX()
{
	return pozycja.x;
}

int Organizm::getY()
{
	return pozycja.y;
}

void Organizm::setWiek(int wartosc) {
	wiek = wartosc;
}

void Organizm::setSila(int wartosc) {
	sila = wartosc;
}

void Organizm::setPozycja(int x, int y) {
	pozycja.x = x;
	pozycja.y = y;
}

void Organizm::aktualizacjaPozycji(int kierunek, int& x, int& y) {
	switch (kierunek) {
	case 0:
		y--;
		break;
	case 1:
		x++;
		break;
	case 2:
		y++;
		break;
	case 3:
		x--;
		break;
	}
}

void Organizm::aktualizacjaCzlowieka(int kierunek, int& x, int& y) {
	int pozycjaX = x;
	int pozycjaY = y;

	switch (kierunek) {
	case 0:
		pozycjaY = y - 1;
		break;
	case 1:
		pozycjaX = x + 1;
		break;
	case 2:
		pozycjaY = y + 1;
		break;
	case 3:
		pozycjaX = x - 1;
		break;
	}
	if (pozycjaX >= 0 && pozycjaX < swiat->getSzerokosc() && pozycjaY >= 0 && pozycjaY < swiat->getWysokosc()) {
		x = pozycjaX;
		y = pozycjaY;
	}
}

void Organizm::dodajWiek() {
	wiek++;
}

void Organizm::dodajSile(int wartosc) {
	this->sila += wartosc;
}