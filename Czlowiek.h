#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int pozostaleTury;
	int turyTrwania;
	bool aktywnaUmiejetnosc;
public:
	Czlowiek(Swiat* swiat, int x, int y);
	~Czlowiek();

	void aktywujUmiejetnosc();
	void akcja(int kierunek);
	void rysowanie() override;
	void kolizja(Organizm* inny) override;
	string nazwa() override;
	Organizm* dziecko(int x, int y) override;
	
	bool czyAktywnaUmiejetnosc();
	int getPozostaleTury();
	int getTuryTrwania();

	void ustawStanUmiejetnosci(bool aktywna, int pozostaleTury, int turyTrwania); 
};