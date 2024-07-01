#include "Roslina.h"

Roslina::Roslina(Swiat* swiat, int sila, int inicjatywa, int x, int y) : Organizm(swiat, sila, inicjatywa, x, y) {}

Roslina::~Roslina() {};

void Roslina::akcja() {
    int random = rand() % 10;
    if (!random) {
        int pozycjaX = pozycja.x, pozycjaY = pozycja.y;
        int kierunek = swiat->znajdzPole(pozycja.x, pozycja.y);
        if (kierunek != -1) {
            aktualizacjaPozycji(kierunek, pozycjaX, pozycjaY);
            swiat->dodajOrganizm(dziecko(pozycjaX, pozycjaY));
        }
    }
}

void Roslina::cofnijOrganizm() {};