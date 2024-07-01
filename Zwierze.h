#pragma once
#include "Organizm.h"

struct staraPozycja {
	int x; 
	int y;
};

class Zwierze : public Organizm {
protected:
	staraPozycja staraPozycja;
	virtual int randomRuch();
	void cofnijOrganizm() override;
public:
	Zwierze(Swiat* swait, int sila, int inicjatywa, int x, int y);

	void akcja() override;
	void kolizja(Organizm* inny) override;
	virtual void rysowanie() = 0;
};