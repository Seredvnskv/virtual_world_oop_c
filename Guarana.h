#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(Swiat* swiat, int x, int y);
	~Guarana();

	void kolizja(Organizm* inny) override;
	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};
