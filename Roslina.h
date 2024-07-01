#pragma once
#include "Organizm.h"
#include "Czlowiek.h"

class Roslina : public Organizm {
public:
	Roslina(Swiat* swait, int sila, int inicjatywa, int x, int y);
	virtual ~Roslina();

	void akcja() override;
	void kolizja(Organizm* inny) = 0;
	virtual void rysowanie() = 0;
	void cofnijOrganizm(); 
};