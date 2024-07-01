#pragma once
#include "Swiat.h"
#include <string>

using namespace std;

struct Pozycja {
	int x;
	int y;
};

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa; 
	int wiek;
	Pozycja pozycja;
	Swiat* swiat;
public:
	Organizm(Swiat* swiat, int sila, int inicjatywa, int x, int y);
	virtual ~Organizm();

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* inny) = 0;
	virtual void cofnijOrganizm() = 0;
	virtual void rysowanie() = 0;
	virtual string nazwa() = 0;
	virtual Organizm* dziecko(int x, int y) = 0;

	int getSila();
	int getInicjatywa();
	int getWiek();
	int getX();
	int getY();

	void setWiek(int wartosc);
	void setSila(int wartosc);
	void setPozycja(int x, int y);
	void aktualizacjaPozycji(int kierunek, int& x, int& y);
	void aktualizacjaCzlowieka(int kierunek, int& x, int& y);

	void dodajSile(int wartosc);
	void dodajWiek();
};