#include "Swiat.h"
#include "Czlowiek.h"

Swiat::Swiat(int szerokosc, int wysokosc)
    : szerokosc(szerokosc), wysokosc(wysokosc), mapa(wysokosc, std::vector<Organizm*>(szerokosc, nullptr)), tura(0) {}

Swiat::~Swiat() {
    for (auto organizm : organizmy) {
        delete organizm;
    }
    organizmy.clear();
}

void Swiat::dodajOrganizm(Organizm* organizm) {
    organizmy.push_back(organizm);
    mapa[organizm->getY()][organizm->getX()] = organizm;
}

void Swiat::usunOrganizm(Organizm* organizm) {
    for (int y = 0; y < wysokosc; y++) {
        for (int x = 0; x < szerokosc; x++) {
            if (mapa[y][x] == organizm) {
                mapa[y][x] = nullptr;
                break;
            }
        }
    }

    list<Organizm*>::iterator i = organizmy.begin();
    do {
        if (*i == organizm) {
            Organizm* dying = *i;
            *i = nullptr;
            delete[] dying;
        }
        else ++i;
    } while (i != organizmy.end());
}

Organizm* Swiat::getOrganizm(int x, int y) {
    if (x >= 0 && x < szerokosc && y >= 0 && y < wysokosc) {
        return mapa[y][x];
    }
    else {
        return nullptr;
    }
}

void Swiat::aktualizujOrganizmy() {
    organizmy.remove_if([](Organizm* organizm) { return organizm == nullptr; });
}

void Swiat::rysujSwiat() {
    cout << "STEROWANIE: RUCH - STRZALKI, UMIEJETNOSC - SPACJA, WYJDZ - X, ZAPISZ - S, WCZYTAJ - R" << endl;
    cout << "TURA: " << tura << endl;
    cout << "@";
    for (int x = 0; x < szerokosc; x++) {
        cout << "@@";
    }
    cout << "@" << endl;

    for (int y = 0; y < wysokosc; y++) {
        cout << "@";
        for (int x = 0; x < szerokosc; x++) {
            if (mapa[y][x] == nullptr) {
                cout << " " << " ";
            }
            else {
                mapa[y][x]->rysowanie();
            }
        }
        cout << "@" << endl;
    }

    cout << "@";
    for (int x = 0; x < szerokosc; x++) {
        cout << "@@";
    }
    cout << "@" << endl;

    zdarzenia.wyswietlZdarzenia();
}

void Swiat::aktualizujSwiat() {
    for (auto& row : mapa) {
        std::fill(row.begin(), row.end(), nullptr);
    }
    for (auto organizm : organizmy) {
        if (organizm) {
            mapa[organizm->getY()][organizm->getX()] = organizm;
        }
    }
}

void Swiat::wykonajTure() {
    zdarzenia.wyczyscZdarzenia();
    kolejnoscRuchu();

    for (auto organizm : organizmy) {
        if (organizm != nullptr) {
            mapa[organizm->getY()][organizm->getX()] = nullptr;
            organizm->akcja();

            auto target = mapa[organizm->getY()][organizm->getX()];
            if (target != nullptr) {
                target->kolizja(organizm);
            }
            aktualizujSwiat();
        }
    }

    aktualizujOrganizmy();
    tura++;
}

void Swiat::wykonajTure(int kierunek) {
    zdarzenia.wyczyscZdarzenia();
    kolejnoscRuchu();

    for (auto organizm : organizmy) {
        if (organizm != nullptr) {
            mapa[organizm->getY()][organizm->getX()] = nullptr;
            
            Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizm);
            
            if (czlowiek) {
                czlowiek->akcja(kierunek);
            }
            else {
                organizm->akcja();
            }

            auto target = mapa[organizm->getY()][organizm->getX()];
            if (target != nullptr) {
                target->kolizja(organizm);
            }
            aktualizujSwiat();
        }
    }

    aktualizujOrganizmy();
    tura++;
}

void Swiat::event(const string& event) {
    zdarzenia.dodaj(event);
}

int Swiat::getSzerokosc() {
    return szerokosc;
}

int Swiat::getWysokosc() {
    return wysokosc;
}

int Swiat::getTura() {
    return tura;
}

void Swiat::setTura(int wartosc) {
    this->tura = wartosc;
}

list<Organizm*>& Swiat::getList() {
    return organizmy;
}

int Swiat::znajdzPole(int x, int y) {
    vector<int> kierunek;

    if (y > 0 && mapa[y - 1][x] == nullptr) {
        kierunek.push_back(0);
    }
    if (x < szerokosc - 1 && mapa[y][x + 1] == nullptr) {
        kierunek.push_back(1);
    }
    if (y < wysokosc - 1 && mapa[y + 1][x] == nullptr) {
        kierunek.push_back(2);
    }
    if (x > 0 && mapa[y][x - 1] == nullptr) {
        kierunek.push_back(3);
    }

    if (kierunek.empty()) {
        return -1;
    }
    else {
        return kierunek[rand() % kierunek.size()];
    }
}

void Swiat::kolejnoscRuchu() {
    organizmy.sort([](Organizm* a, Organizm* b) {
        if (a->getInicjatywa() == b->getInicjatywa()) {
            return a->getWiek() > b->getWiek();
        }
        return a->getInicjatywa() > b->getInicjatywa();
    });
}

void Swiat::aktywujUmiejetnoscCzlowieka() {
    for (auto organizm : organizmy) {
        Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizm);
        if (czlowiek) {
            czlowiek->aktywujUmiejetnosc();
            break;
        }
    }
}