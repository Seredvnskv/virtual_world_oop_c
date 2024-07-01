#pragma once
#include "Roslina.h"
#include "Zwierze.h"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(Swiat* swiat, int x, int y);
	~BarszczSosnowskiego();

	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm* inny) override;
	string nazwa() override;

	Organizm* dziecko(int x, int y) override;
	void zabij(Organizm* organizm);
};