#include "TworzSwiat.h"

void TworzSwiat::losujPozycje(int& x, int& y) {
	do {
		x = rand() % swiat->getSzerokosc();
		y = rand() % swiat->getWysokosc();
	} while (swiat->getOrganizm(x, y) != nullptr); 
}

TworzSwiat::TworzSwiat(int szerokosc, int wysokosc) {
	swiat = new Swiat(szerokosc, wysokosc);
}

TworzSwiat::~TworzSwiat() {};

Swiat* TworzSwiat::tworz() {
	int x, y;

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Czlowiek(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Trawa(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Trawa(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Mlecz(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Mlecz(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Guarana(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Guarana(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new WilczeJagody(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new WilczeJagody(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new BarszczSosnowskiego(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new BarszczSosnowskiego(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Owca(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Owca(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Wilk(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Wilk(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Lis(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Lis(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Antylopa(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Antylopa(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Zolw(swiat, x, y));

	losujPozycje(x, y);
	swiat->dodajOrganizm(new Zolw(swiat, x, y));

	return swiat;
}

Organizm* TworzSwiat::dodajZapisanyOrganizm(const string& nazwa, int x, int y, int sila, int wiek) {
	Organizm* organizm = nullptr;

	if (nazwa == "Wilk") {
		organizm = new Wilk(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Owca") {
		organizm = new Owca(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Lis") {
		organizm = new Lis(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Antylopa") {
		organizm = new Antylopa(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Zolw") {
		organizm = new Zolw(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Trawa") {
		organizm = new Trawa(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Mlecz") {
		organizm = new Mlecz(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Guarana") {
		organizm = new Guarana(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Wilcze_Jagody") {
		organizm = new WilczeJagody(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}
	else if (nazwa == "Barszcz_Sosnowskiego") {
		organizm = new BarszczSosnowskiego(swiat, x, y);
		organizm->setSila(sila);
		organizm->setWiek(wiek);
	}

	return organizm;
}

Organizm* TworzSwiat::dodajZapisanegoCzlowieka(const string& nazwa, int x, int y, int sila, int wiek, int aktywna, int pozostaleTury, int turyTrwania) {
	Organizm* organizm = nullptr;

	if (nazwa == "Czlowiek") {
		Czlowiek* czlowiek = new Czlowiek(swiat, x, y);
		czlowiek->setSila(sila);
		czlowiek->setWiek(wiek);
		czlowiek->ustawStanUmiejetnosci(aktywna != 0, pozostaleTury, turyTrwania);
		organizm = czlowiek;
	}

	return organizm;
}

void TworzSwiat::saveGame() {
	ofstream file("savegame.txt");

	file << swiat->getSzerokosc() << " " << swiat->getWysokosc() << " " << swiat->getTura() << endl;

	list<Organizm*>& organizmy = swiat->getList();
	for (auto& organizm : organizmy) {
		file << organizm->nazwa() << " "
			<< organizm->getX() << " "
			<< organizm->getY() << " "
			<< organizm->getSila() << " "
			<< organizm->getWiek() << " ";

		Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizm);
		if (czlowiek != nullptr) {
			file << czlowiek->czyAktywnaUmiejetnosc() << " "
				<< czlowiek->getPozostaleTury() << " "
				<< czlowiek->getTuryTrwania() << " ";
		}

		file << endl;
	}

	file.close();
	swiat->event("ZAPISANO STAN GRY");
}

void TworzSwiat::loadGame() {
	ifstream file("savegame.txt");

	int szerokosc, wysokosc, tura;
	file >> szerokosc >> wysokosc >> tura;

	delete swiat;
	swiat = new Swiat(szerokosc, wysokosc);
	swiat->setTura(tura);

	string nazwa;
	int x, y, sila, wiek, aktywnaUmiejetnosc, pozostaleTury, turyTrwania;
	while (file >> nazwa >> x >> y >> sila >> wiek) {
		if (nazwa == "Czlowiek") {
			file >> aktywnaUmiejetnosc >> pozostaleTury >> turyTrwania;
			Organizm* czlowiek = dodajZapisanegoCzlowieka(nazwa, x, y, sila, wiek, aktywnaUmiejetnosc, pozostaleTury, turyTrwania);
			swiat->dodajOrganizm(czlowiek);
		}
		else {
			Organizm* organizm = dodajZapisanyOrganizm(nazwa, x, y, sila, wiek);
			swiat->dodajOrganizm(organizm);
		}
	}

	file.close();
	swiat->event("WCZYTANO STAN GRY");
}