#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(Swiat* swiat, int x, int y);
	~Lis();

	int randomRuch() override;
	void rysowanie() override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
};