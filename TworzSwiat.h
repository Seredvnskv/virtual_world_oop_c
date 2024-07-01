#pragma once
#include <fstream>
#include <sstream>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

class TworzSwiat {
private:
	Swiat* swiat;
	void losujPozycje(int& x, int& y);
public:
	TworzSwiat(int szerokosc, int wysokosc);
	~TworzSwiat();

	Swiat* tworz();
	Organizm* dodajZapisanyOrganizm(const string& nazwa, int x, int y, int sila, int wiek);
	Organizm* dodajZapisanegoCzlowieka(const string& nazwa, int x, int y, int sila, int wiek, int aktywna, int pozostaleTury, int turyTrwania);

	void saveGame();
	void loadGame();
};