#pragma once
#include "Organizm.h"
#include "Zdarzenie.h"
#include <vector>
#include <list>
#include <algorithm>
#include <conio.h>
#include <iostream>

using namespace std;

class Organizm;

class Swiat {
private:
	int szerokosc, wysokosc; 
	list<Organizm*> organizmy;
	vector<vector<Organizm*>> mapa;
    
    int tura;
    Zdarzenia zdarzenia; 
public:
    Swiat(int szerokosc, int wysokosc);
    ~Swiat();

    void rysujSwiat();
    void aktualizujSwiat();
    void wykonajTure();
    void wykonajTure(int kierunek);
    void event(const string& event);

    int getSzerokosc();
    int getWysokosc();
    int getTura();
    list<Organizm*>& getList(); 

    void setTura(int wartosc);
    void dodajOrganizm(Organizm* organizm);
    void usunOrganizm(Organizm* organizm);
    Organizm* getOrganizm(int x, int y);
    void aktualizujOrganizmy();

    int znajdzPole(int x, int y);
    void kolejnoscRuchu();

    void aktywujUmiejetnoscCzlowieka();
};