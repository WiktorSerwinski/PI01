#include <iostream>
#include <time.h>
#include <windows.h> //dla 'sleep'
using namespace std;

int wariant1, wariant2; // dla wyboru liczby statkow w main
int punkty1 = 0, punkty2 = 0; //dzieki temu wiem kto w koncu wygrywa
void wybor_statkow1(int numer1);
void wybor_statkow2(int numer2);
void plansze_dane(); // gotowe plansze ktore bedziemy nadpisywac
void g1statek2x1();
void g1statek3x1();
void g1statek4x1();
void g2statek2x1();
void g2statek3x1();
void g2statek4x1();
void strzal1();
void strzal2();
void g1s1losowanie();
void g2s1losowanie();
void g1s2losowanie();
void g2s2losowanie();
void g1s3losowanie();
void g2s3losowanie();
void planszaodkryta1();
void planszaodkryta2();
void planszazakryta1();
void planszazakryta2();
char plansza_odkryta1[8][8], plansza_odkryta2[8][8], plansza_zakryta1[8][8], plansza_zakryta2[8][8]; // plansze

int main()
{
    int menu; // menu glowne

MENU: // przypisanie dla funkcji 'goto'
    system("cls");
    cout << "GRA W STATKI\n";
    cout << "Wybierz opcje:\n";
    cout << "1. GRAJ\n";
    cout << "2. ZASADY GRY\n";
    cout << "3. TWORCY\n";
    cin >> menu;

    switch (menu)
    {
    case 1: //opcja dla grania
    {
        system("cls");
        cout << "GRACZ 1:\n";
        plansze_dane();
        cout << "WYBIERZ WARIANT GRY\n\n";
        cout << "Nr. 1 - Trzy statki na 2 pola,   \tDwa statki na 3 pola, \tJeden statek na 4 pola\n";
        cout << "Nr. 2 - Cztery statki na 2 pola, \tTrzy statki na 3 pola, \tDwa statki na 4 pola\n";
        cin >> wariant1;
        wybor_statkow1(wariant1);

        system("cls");
        cout << "GRACZ 2:\n";
        cout << "WYBIERZ WARIANT GRY\n\n";
        cout << "Nr. 1 - Trzy statki na 2 pola,   \tDwa statki na 3 pola, \tJeden statek na 4 pola\n";
        cout << "Nr. 2 - Cztery statki na 2 pola, \tTrzy statki na 3 pola, \tDwa statki na 4 pola\n";
        cin >> wariant2;
        wybor_statkow2(wariant2);

        for (;;)
        {
            strzal1();
            if (wariant2 == 1 && punkty1 == 16)
            {
                cout << "GRACZ 1 WYGRAL!!!!";
                Sleep(3000);
                break;
            }
            else if (wariant2 == 2 && punkty1 == 25)
            {
                cout << "GRACZ 1 WYGRAL!!!!";
                Sleep(3000);
                break;
            }
            system("cls");
            cout << "Zmiana gracza - 5 sekund na zmiane";
            Sleep(5000);
            system("cls");
            strzal2();
            if (wariant1 == 1 && punkty2 == 16)
            {
                cout << "GRACZ 2 WYGRAL!!!!";
                Sleep(3000);
                break;
            }
            else if (wariant1 == 2 && punkty2 == 25)
            {
                cout << "GRACZ 2 WYGRAL!!!!";
                Sleep(3000);
                break;
            }
        }

        system("cls");
        cout << "\nDziekuje za gre!!!";


    }
    break;

    case 2:
    {
        cout << "\nZASADY:";
        cout << "\nGra w statki polega na odgadywaniu w ktorym miejscu moze znajdowac sie uprzednio przydzielony\n przez innego gracza statek.";
        cout << "\n Wygrywa gracz, ktory odgadnie wszystkie pola na ktorych sa statki przeciwnika";
        cout << "\n\nGra jest turowa, jesli ktos trafia to ma kolejna szanse, a jesli nie to odgaduje przeciwnik";
        Sleep(10000);
        goto MENU;
    }
    break;

    case 3:
    {
        system("cls");
        cout << "Gre wykonal:\n\tMikolaj Plader IO\noraz\tWiktor Serwinski IO";
        Sleep(3000);
        goto MENU;
    }
    break;

    default: //dla zlego wyboru w menu
    {
        system("cls");
        cout << "Bledny wybor, sprobuj ponownie za chwile\n";
        Sleep(1500);
        goto MENU;
    }
    break;
    }
    return 0;
}

void wybor_statkow1(int numer1)
{

MENU1a:
    switch (numer1)
    {
    case 1:
    {
        system("cls");
        planszaodkryta1();
        cout << "Pierwszy statek\n"; // przypisywanie od razu gotowego kodu wpisujacego statki na plansze
        g1statek2x1();
        cout << "Drugi statek\n";
        g1statek2x1();
        cout << "Trzeci statek\n";
        g1statek2x1();
        cout << "Czwarty statek\n";
        g1statek3x1();
        cout << "Piaty statek\n";
        g1statek3x1();
        cout << "Szosty statek\n";
        g1statek4x1();
    }
    break;
    case 2:
    {
        system("cls");
        planszaodkryta1();
        cout << "Pierwszy statek\n"; // przypisywanie od razu gotowego kodu wpisujacego statki na plansze
        g1statek2x1();
        cout << "Drugi statek\n";
        g1statek2x1();
        cout << "Trzeci statek\n";
        g1statek2x1();
        cout << "Czwarty statek\n";
        g1statek2x1();
        cout << "Piaty statek\n";
        g1statek3x1();
        cout << "Szosty statek\n";
        g1statek3x1();
        cout << "Siodmy statek\n";
        g1statek3x1();
        cout << "Osmy statek\n";
        g1statek4x1();
        cout << "Dziewiaty statek\n";
        g1statek4x1();
    }
    break;

    default:
    {
        cout << "\nNiepoprawny wybor!\nSprobuj ponownie!";
        Sleep(1000);
        system("cls");
        cout << "WYBIERZ WARIANT GRY\n\n";
        cout << "Nr. 1 - Trzy statki na 2 pola,   \tDwa statki na 3 pola, \tJeden statek na 4 pola\n";
        cout << "Nr. 2 - Cztery statki na 2 pola, \tTrzy statki na 3 pola, \tDwa statki na 4 pola\n";
        cin >> numer1;
        goto MENU1a;

    }
    break;
    }
}
void wybor_statkow2(int numer2)
{

MENU1b:
    switch (numer2)
    {
    case 1:
    {
        system("cls");
        planszaodkryta2();
        cout << "Pierwszy statek\n"; // przypisywanie od razu gotowego kodu wpisujacego statki na plansze
        g2statek2x1();
        cout << "Drugi statek\n";
        g2statek2x1();
        cout << "Trzeci statek\n";
        g2statek2x1();
        cout << "Czwarty statek\n";
        g2statek3x1();
        cout << "Piaty statek\n";
        g2statek3x1();
        cout << "Szosty statek\n";
        g2statek4x1();
    }
    break;
    case 2:
    {
        system("cls");
        planszaodkryta2();
        cout << "Pierwszy statek\n"; // przypisywanie od razu gotowego kodu wpisujacego statki na plansze
        g2statek2x1();
        cout << "Drugi statek\n";
        g2statek2x1();
        cout << "Trzeci statek\n";
        g2statek2x1();
        cout << "Czwarty statek\n";
        g2statek2x1();
        cout << "Piaty statek\n";
        g2statek3x1();
        cout << "Szosty statek\n";
        g2statek3x1();
        cout << "Siodmy statek\n";
        g2statek3x1();
        cout << "Osmy statek\n";
        g2statek4x1();
        cout << "Dziewiaty statek\n";
        g2statek4x1();
    }
    break;

    default:
    {
        cout << "\nNiepoprawny wybor!\nSprobuj ponownie!";
        Sleep(1000);
        system("cls");
        cout << "WYBIERZ WARIANT GRY\n\n";
        cout << "Nr. 1 - Trzy statki na 2 pola,   \tDwa statki na 3 pola, \tJeden statek na 4 pola\n";
        cout << "Nr. 2 - Cztery statki na 2 pola, \tTrzy statki na 3 pola, \tDwa statki na 4 pola\n";
        cin >> numer2;
        goto MENU1b;

    }
    break;
    }
}

void plansze_dane()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            plansza_odkryta1[i][j] = ' ';
            plansza_odkryta2[i][j] = ' ';
            plansza_zakryta1[i][j] = ' ';
            plansza_zakryta2[i][j] = ' ';
        }
    }
}

void planszaodkryta1()
{
    cout << "|WK|K1|K2|K3|K4|K5|K6|K7|K8|\n";
    cout << "----------------------------\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "|W" << i + 1 ;
        for (int j = 0; j < 8; j++)
        {
            cout << "|" << plansza_odkryta1[i][j] <<" ";
        }
        cout << "|\n";
        cout << "----------------------------\n";
    }
    
}
void planszaodkryta2()
{
    cout << "|WK|K1|K2|K3|K4|K5|K6|K7|K8|\n";
    cout << "----------------------------\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "|W" << i + 1;
        for (int j = 0; j < 8; j++)
        {
            cout << "|" << plansza_odkryta2[i][j] << " ";
        }
        cout << "|\n";
        cout << "----------------------------\n";
    }

}
void planszazakryta1()
{
    cout << "|WK|K1|K2|K3|K4|K5|K6|K7|K8|\n";
    cout << "----------------------------\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "|W" << i + 1;
        for (int j = 0; j < 8; j++)
        {
            cout << "|" << plansza_zakryta1[i][j] << " ";
        }
        cout << "|\n";
        cout << "----------------------------\n";
    }

}
void planszazakryta2()
{
   
    cout << "|WK|K1|K2|K3|K4|K5|K6|K7|K8|\n";
    cout << "----------------------------\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "|W" << i + 1;
        for (int j = 0; j < 8; j++)
        {
            cout << "|" << plansza_zakryta2[i][j] << " ";
        }
        cout << "|\n";
        cout << "----------------------------\n";
    }

}

void g1statek2x1() // komenda na statek 2x1 i wykrywa czy poprzednie statki nie stoja w miejscu w ktorym chcemy ulokowac ten
{
    int pion_poziom;
MENU2:
    cout << "Statek 2x1, 1. poziomo, 2. pionowo czy 3. losowo?\n";
    cin >> pion_poziom;
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta1();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w prawo)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU2;
        }
        if (wiersz > 8 || kolumna > 7)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU2;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 2:
    {
        planszaodkryta1();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w dol)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz][kolumna - 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU2;
        }
        if (wiersz > 7 || kolumna > 8)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU2;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz][kolumna - 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 3:
    {
        g1s1losowanie();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta1();
        goto MENU2;
    }
    break;
    }
}
void g1statek3x1()
{
    int pion_poziom;
MENU3:
    cout << "Statek 3x1, 1. poziomo, 2. pionowo czy 3. losowo?\n";
    cin >> pion_poziom;
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta1();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w prawo)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna] == '*') || (plansza_odkryta1[wiersz - 1][kolumna + 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU3;
        }
        if (wiersz > 8 || kolumna > 6)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU3;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna] = '*';
        plansza_odkryta1[wiersz - 1][kolumna + 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 2:
    {
        planszaodkryta1();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w dol)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz][kolumna - 1] == '*') || (plansza_odkryta1[wiersz + 1][kolumna - 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU3;
        }
        if (wiersz > 6 || kolumna > 8)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU3;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz][kolumna - 1] = '*';
        plansza_odkryta1[wiersz + 1][kolumna - 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 3:
    {
        g1s2losowanie();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta1();
        goto MENU3;
    }
    break;
    }
}
void g1statek4x1()
{
    int pion_poziom;
MENU4:
    cout << "Statek 4x1, 1. poziomo, 2. pionowo czy 3. losowo?\n";
    cin >> pion_poziom;
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta1();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w prawo)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna] == '*') || (plansza_odkryta1[wiersz - 1][kolumna + 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna + 2] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU4;
        }
        if (wiersz > 8 || kolumna > 5)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU4;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna] = '*';
        plansza_odkryta1[wiersz - 1][kolumna + 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna + 2] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 2:
    {
        planszaodkryta1();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w dol)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz][kolumna - 1] == '*') || (plansza_odkryta1[wiersz + 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz + 2][kolumna - 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU4;
        }
        if (wiersz > 5 || kolumna > 8)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta1();
            goto MENU4;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz][kolumna - 1] = '*';
        plansza_odkryta1[wiersz + 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz + 2][kolumna - 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 3:
    {
        g1s3losowanie();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta1();
        goto MENU4;
    }
    break;
    }
}

void g2statek2x1() // komenda na statek 2x1 i wykrywa czy poprzednie statki nie stoja w miejscu w ktorym chcemy ulokowac ten
{
    int pion_poziom;
MENU2:
    cout << "Statek 2x1, 1. poziomo, 2. pionowo czy 3. losowo?\n";
    cin >> pion_poziom;
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta2();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w prawo)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU2;
        }
        if (wiersz > 8 || kolumna > 7)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU2;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 2:
    {
        planszaodkryta2();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w dol)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz][kolumna - 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU2;
        }
        if (wiersz > 7 || kolumna > 8)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU2;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz][kolumna - 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 3:
    {
        g2s1losowanie();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta2();
        goto MENU2;
    }
    break;
    }
}
void g2statek3x1()
{
    int pion_poziom;
MENU3:
    cout << "Statek 3x1, 1. poziomo, 2. pionowo czy 3. losowo?\n";
    cin >> pion_poziom;
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta2();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w prawo)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna] == '*') || (plansza_odkryta2[wiersz - 1][kolumna + 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU3;
        }
        if (wiersz > 8 || kolumna > 6)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU3;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna] = '*';
        plansza_odkryta2[wiersz - 1][kolumna + 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 2:
    {
        planszaodkryta2();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w dol)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz][kolumna - 1] == '*') || (plansza_odkryta2[wiersz + 1][kolumna - 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU3;
        }
        if (wiersz > 6 || kolumna > 8)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU3;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz][kolumna - 1] = '*';
        plansza_odkryta2[wiersz + 1][kolumna - 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 3:
    {
        g2s2losowanie();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta2();
        goto MENU3;
    }
    break;
    }
}
void g2statek4x1()
{
    int pion_poziom;
MENU4:
    cout << "Statek 4x1, 1. poziomo, 2. pionowo czy 3. losowo?\n";
    cin >> pion_poziom;
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta2();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w prawo)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna] == '*') || (plansza_odkryta2[wiersz - 1][kolumna + 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna + 2] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU4;
        }
        if (wiersz > 8 || kolumna > 5)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU4;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna] = '*';
        plansza_odkryta2[wiersz - 1][kolumna + 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna + 2] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 2:
    {
        planszaodkryta2();
        cout << "\nWiersz i kolumna poczatku statku (od miejsca startowego statek przypisuje sie w dol)\n";
        cout << "Wiersz: ";
        cin >> wiersz;
        cout << "Kolumna: ";
        cin >> kolumna;
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz][kolumna - 1] == '*') || (plansza_odkryta2[wiersz + 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz + 2][kolumna - 1] == '*'))
        {
            cout << "\nW tym miejscu jest juz inny statek!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU4;
        }
        if (wiersz > 5 || kolumna > 8)
        {
            cout << "\nNiepoprawny wiersz lub kolumna (maksymalnie 8)!\n\nWybierz ponownie za chwile\n";
            Sleep(1500);
            system("cls");
            planszaodkryta2();
            goto MENU4;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz][kolumna - 1] = '*';
        plansza_odkryta2[wiersz + 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz + 2][kolumna - 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 3:
    {
        g2s3losowanie();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta2();
        goto MENU4;
    }
    break;
    }
}

void strzal1()
{
    int wiersz, kolumna;
MENU_strzal1:

    system("cls");
    cout << "Legedna: * statek\n         0 strzal niecelny\n         X strzal celny\n";
    cout << "\t\tGracz 1 oddaje strzal";
    cout << "\nTwoja plansza:\n\n";
    planszaodkryta1();
    cout << "\nPlansza wroga:\n\n";
    planszazakryta2();
    cout << "\nWiersz: ";
    cin >> wiersz;
    cout << "Kolumna: ";
    cin >> kolumna;
    if (wiersz > 8 || kolumna > 8)
    {
        cout << "Wiersz i kolumna moga miec maksymalnie wartosc 8!\nSprobuj ponownie!";
        Sleep(1500);
        system("cls");
        goto MENU_strzal1;
    }
    if (plansza_odkryta2[wiersz - 1][kolumna - 1] == '*')
    {
        cout << "\nTrafiles, graj dalej!";
        plansza_zakryta2[wiersz - 1][kolumna - 1] = 'X';
        plansza_odkryta2[wiersz - 1][kolumna - 1] = 'X';
        punkty1++;
        Sleep(1500);
        goto MENU_strzal1;
    }
    else if (plansza_odkryta1[wiersz - 1][kolumna - 1] == '0')
    {
        cout << "\nJuz tu strzelales!";
        Sleep(1000);
        system("cls");
        goto MENU_strzal1;
    }
    else if (plansza_odkryta2[wiersz - 1][kolumna - 1] != '*')
    {
        cout << "\nNie trafiles!";
        plansza_zakryta2[wiersz - 1][kolumna - 1] = '0';
        Sleep(1000);
        system("cls");
    }
}
void strzal2()
{
    int wiersz, kolumna;
MENU_strzal2:

    system("cls");
    cout << "Legedna: * statek\n         0 strzal niecelny\n         X strzal celny\n";
    cout << "\t\tGracz 2 oddaje strzal";
    cout << "\nTwoja plansza:\n\n";
    planszaodkryta2();
    cout << "\nPlansza wroga:\n\n";
    planszazakryta1();
    cout << "\nWiersz: ";
    cin >> wiersz;
    cout << "Kolumna: ";
    cin >> kolumna;
    if (wiersz > 8 || kolumna > 8)
    {
        cout << "Wiersz i kolumna moga miec maksymalnie wartosc 8!\nSprobuj ponownie!";
        Sleep(1500);
        system("cls");
        goto MENU_strzal2;
    }
    if (plansza_odkryta1[wiersz - 1][kolumna - 1] == '*')
    {
        cout << "\nTrafiles, graj dalej!";
        plansza_zakryta1[wiersz - 1][kolumna - 1] = 'X';
        plansza_odkryta1[wiersz - 1][kolumna - 1] = 'X';
        punkty2++;
        Sleep(1500);
        goto MENU_strzal2;
    }
    else if(plansza_odkryta1[wiersz - 1][kolumna - 1] == '0')
    {
        cout << "\nJuz tu strzelales!";
        Sleep(1000);
        system("cls");
        goto MENU_strzal2;
    }
    else if (plansza_odkryta1[wiersz - 1][kolumna - 1] != '*')
    {
        cout << "\nNie trafiles!";
        plansza_zakryta1[wiersz - 1][kolumna - 1] = '0';
        Sleep(1000);
        system("cls");
    }

}

void g1s1losowanie()
{
    int pion_poziom;
MENU2:

    pion_poziom = 1 + rand() % (2 - 1 + 1);
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta1();
        wiersz = 1 + rand() % (8 - 1 + 1);
        kolumna = 1 + rand() % (7 - 1 + 1);
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna] == '*'))
        {
            goto MENU2;
        }

        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 2:
    {
        planszaodkryta1();
        wiersz = 1 + rand() % (7 - 1 + 1);
        kolumna = 1 + rand() % (8 - 1 + 1);
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz][kolumna - 1] == '*'))
        {
            goto MENU2;
        }

        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz][kolumna - 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta1();
        goto MENU2;
    }
    break;
    }
}
void g2s1losowanie()
{
    int pion_poziom;
MENU2:

    pion_poziom = 1 + rand() % (2 - 1 + 1);
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta2();
        wiersz = 1 + rand() % (8 - 1 + 1);
        kolumna = 1 + rand() % (7 - 1 + 1);
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna] == '*'))
        {
            goto MENU2;
        }

        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 2:
    {
        planszaodkryta2();
        wiersz = 1 + rand() % (7 - 1 + 1);
        kolumna = 1 + rand() % (8 - 1 + 1);
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz][kolumna - 1] == '*'))
        {
            goto MENU2;
        }

        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz][kolumna - 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta2();
        goto MENU2;
    }
    break;
    }
}
void g1s2losowanie()
{
    int pion_poziom;
MENU3:
    pion_poziom = 1 + rand() % (2 - 1 + 1);
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta1();
        wiersz = 1 + rand() % (8 - 1 + 1);
        kolumna = 1 + rand() % (6 - 1 + 1);
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna] == '*') || (plansza_odkryta1[wiersz - 1][kolumna + 1] == '*'))
        {
            system("cls");
            planszaodkryta1();
            goto MENU3;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna] = '*';
        plansza_odkryta1[wiersz - 1][kolumna + 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 2:
    {
        planszaodkryta1();
        wiersz = 1 + rand() % (6 - 1 + 1);
        kolumna = 1 + rand() % (8 - 1 + 1);
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz][kolumna - 1] == '*') || (plansza_odkryta1[wiersz + 1][kolumna - 1] == '*'))
        {
            system("cls");
            planszaodkryta1();
            goto MENU3;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz][kolumna - 1] = '*';
        plansza_odkryta1[wiersz + 1][kolumna - 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta1();
        goto MENU3;
    }
    break;
    }
}
void g2s2losowanie()
{
    int pion_poziom;
MENU3:
    pion_poziom = 1 + rand() % (2 - 1 + 1);
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta2();
        wiersz = 1 + rand() % (8 - 1 + 1);
        kolumna = 1 + rand() % (6 - 1 + 1);
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna] == '*') || (plansza_odkryta2[wiersz - 1][kolumna + 1] == '*'))
        {
            system("cls");
            planszaodkryta2();
            goto MENU3;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna] = '*';
        plansza_odkryta2[wiersz - 1][kolumna + 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 2:
    {
        planszaodkryta2();
        wiersz = 1 + rand() % (6 - 1 + 1);
        kolumna = 1 + rand() % (8 - 1 + 1);
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz][kolumna - 1] == '*') || (plansza_odkryta2[wiersz + 1][kolumna - 1] == '*'))
        {
            system("cls");
            planszaodkryta2();
            goto MENU3;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz][kolumna - 1] = '*';
        plansza_odkryta2[wiersz + 1][kolumna - 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta2();
        goto MENU3;
    }
    break;
    }
}
void g1s3losowanie()
{
    int pion_poziom;
MENU4:
    pion_poziom = 1 + rand() % (2 - 1 + 1);
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta1();
        wiersz = 1 + rand() % (8 - 1 + 1);
        kolumna = 1 + rand() % (5 - 1 + 1);
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna] == '*') || (plansza_odkryta1[wiersz - 1][kolumna + 1] == '*') || (plansza_odkryta1[wiersz - 1][kolumna + 2] == '*'))
        {
            system("cls");
            planszaodkryta1();
            goto MENU4;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna] = '*';
        plansza_odkryta1[wiersz - 1][kolumna + 1] = '*';
        plansza_odkryta1[wiersz - 1][kolumna + 2] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    case 2:
    {
        planszaodkryta1();
        wiersz = 1 + rand() % (5 - 1 + 1);
        kolumna = 1 + rand() % (8 - 1 + 1);
        if ((plansza_odkryta1[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz][kolumna - 1] == '*') || (plansza_odkryta1[wiersz + 1][kolumna - 1] == '*') || (plansza_odkryta1[wiersz + 2][kolumna - 1] == '*'))
        {
            system("cls");
            planszaodkryta1();
            goto MENU4;
        }
        plansza_odkryta1[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz][kolumna - 1] = '*';
        plansza_odkryta1[wiersz + 1][kolumna - 1] = '*';
        plansza_odkryta1[wiersz + 2][kolumna - 1] = '*';
        system("cls");
        planszaodkryta1();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta1();
        goto MENU4;
    }
    break;
    }
}
void g2s3losowanie()
{
    int pion_poziom;
MENU4:
    pion_poziom = 1 + rand() % (2 - 1 + 1);
    system("cls");
    switch (pion_poziom)
    {
        int wiersz, kolumna;
    case 1:
    {
        planszaodkryta2();
        wiersz = 1 + rand() % (8 - 1 + 1);
        kolumna = 1 + rand() % (5 - 1 + 1);
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna] == '*') || (plansza_odkryta2[wiersz - 1][kolumna + 1] == '*') || (plansza_odkryta2[wiersz - 1][kolumna + 2] == '*'))
        {
            system("cls");
            planszaodkryta2();
            goto MENU4;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna] = '*';
        plansza_odkryta2[wiersz - 1][kolumna + 1] = '*';
        plansza_odkryta2[wiersz - 1][kolumna + 2] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    case 2:
    {
        planszaodkryta2();
        wiersz = 1 + rand() % (5 - 1 + 1);
        kolumna = 1 + rand() % (8 - 1 + 1);
        if ((plansza_odkryta2[wiersz - 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz][kolumna - 1] == '*') || (plansza_odkryta2[wiersz + 1][kolumna - 1] == '*') || (plansza_odkryta2[wiersz + 2][kolumna - 1] == '*'))
        {
            system("cls");
            planszaodkryta2();
            goto MENU4;
        }
        plansza_odkryta2[wiersz - 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz][kolumna - 1] = '*';
        plansza_odkryta2[wiersz + 1][kolumna - 1] = '*';
        plansza_odkryta2[wiersz + 2][kolumna - 1] = '*';
        system("cls");
        planszaodkryta2();
    }
    break;
    default:
    {
        cout << "Bledny wybor, sprobuj ponownie za chwile";
        Sleep(1500);
        system("cls");
        planszaodkryta2();
        goto MENU4;
    }
    break;
    }
}