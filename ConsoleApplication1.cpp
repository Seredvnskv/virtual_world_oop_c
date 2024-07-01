#include <iostream>
#include <conio.h>
#include<ctime>
#include "TworzSwiat.h"

#define KEY_X 120
#define KEY_S 115
#define KEY_R 114
#define KEY_SPACE 32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main()
{
    srand(time(NULL));

    system("title SAMBOR SEREDYNSKI 198035");

    int szerokosc, wysokosc;
    cout << "Podaj szerokosc: ";
    cin >> szerokosc;
    cout << "Podaj wysokosc: ";
    cin >> wysokosc;

    system("cls");

    auto utworzSwiat = new TworzSwiat(szerokosc, wysokosc);
    auto swiat = utworzSwiat->tworz();

    bool flag = true;
    int ruch;

    while (flag) {
        system("cls");
        swiat->rysujSwiat();

        int input = _getch();
        if (input && input != 224)
        {
            switch (input) {
            case KEY_X:
                flag = false;
                break;
            case KEY_SPACE:
                swiat->aktywujUmiejetnoscCzlowieka();
                break;
            case KEY_S:
                utworzSwiat->saveGame();
                break;
            case KEY_R:
                utworzSwiat->loadGame();
                break;
            }
        }
        else
        {   
            switch (ruch = _getch()) {
            case KEY_UP:
                swiat->wykonajTure(0);
                break;
            case KEY_RIGHT:
                swiat->wykonajTure(1);
                break;
            case KEY_DOWN:
                swiat->wykonajTure(2);
                break;
            case KEY_LEFT:
                swiat->wykonajTure(3);
                break;
            default:
                swiat->wykonajTure();
                break;
            }
        }
    }

    delete utworzSwiat;

    return 0;
}