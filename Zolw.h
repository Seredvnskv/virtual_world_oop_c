#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
	Zolw(Swiat* swiat, int x, int y);
	~Zolw();

	void akcja() override;
	void kolizja(Organizm* inny) override;
	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};