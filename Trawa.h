#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(Swiat* swiat, int x, int y);
	~Trawa();

	void rysowanie() override;
	void kolizja(Organizm* inny) override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};