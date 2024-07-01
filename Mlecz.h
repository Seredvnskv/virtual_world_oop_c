#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(Swiat* swiat, int x, int y);
	~Mlecz();

	void akcja() override; 
	void kolizja(Organizm* inny) override;
	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};
