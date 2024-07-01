#include "Lis.h"

Lis::Lis(Swiat* swiat, int x, int y) : Zwierze(swiat, 3, 7, x, y) {};

Lis::~Lis() {};

void Lis::rysowanie() {
	cout << "L" << " ";
}

string Lis::nazwa() {
	return "Lis";
}

int Lis::randomRuch() {
	vector<int> kierunek;
	Organizm* target; 

	if (pozycja.y > 0) {
		target = swiat->getOrganizm(pozycja.x, pozycja.y - 1);
		if (target == nullptr || target->getSila() <= this->getSila()) {
			kierunek.push_back(0);
		}
	}
	if (pozycja.x < swiat->getSzerokosc() - 1) {
		target = swiat->getOrganizm(pozycja.x + 1, pozycja.y);
		if (target == nullptr || target->getSila() <= this->getSila()) {
			kierunek.push_back(1);
		}
	}
	if (pozycja.y < swiat->getWysokosc() - 1) {
		target = swiat->getOrganizm(pozycja.x, pozycja.y + 1);
		if (target == nullptr || target->getSila() <= this->getSila()) {
			kierunek.push_back(2);
		}
	}
	if (pozycja.x > 0) {
		target = swiat->getOrganizm(pozycja.x - 1, pozycja.y);
		if (target == nullptr || target->getSila() <= this->getSila()) {
			kierunek.push_back(3);
		}
	}

	if (kierunek.empty()) {
		return -1;
	}

	return kierunek[rand() % kierunek.size()];
}

Organizm* Lis::dziecko(int x, int y) {
	return new Lis(swiat, x, y);
}