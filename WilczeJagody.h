#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(Swiat* swiat, int x, int y);
	~WilczeJagody();

	void kolizja(Organizm* inny) override;
	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};