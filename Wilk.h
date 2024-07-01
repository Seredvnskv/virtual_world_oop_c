#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(Swiat* swiat, int x, int y);
	~Wilk();

	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};
