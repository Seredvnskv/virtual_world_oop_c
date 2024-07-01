#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat* swiat, int x, int y);
	~Antylopa();

	void akcja() override;
	void kolizja(Organizm* inny) override;
	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;

	void ruchAntylopa(int kierunek, int& x, int& y);
};