#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(Swiat* swiat, int x, int y);
	~Owca();

	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};