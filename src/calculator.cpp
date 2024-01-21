#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;

//Sprawdzanie poprawności liczby binarnej
bool poprawnoscbinarny(const char liczba[]) {
    for (int i = 0; i < strlen(liczba); i++) {
        if (liczba[i] != '0' && liczba[i] != '1') {
            return false;
        }
    }
    return true;
}

//konwersja liczby z dowolnego systemu na dziesietny
int dodziesietnego(const char liczba[], int system) {
    if (system == 2 && !poprawnoscbinarny(liczba)) {
        std::cout << "Niepoprawna cyfra w liczbie binarnej!" << std::endl;
        exit(1);
    }

    int wynik = 0, a, b = 1;

    for (int i = strlen(liczba) - 1; i >= 0; i--) {
        if (liczba[i] >= '0' && liczba[i] <= '9')
            a = liczba[i] - '0';
        else if (liczba[i] >= 'A' && liczba[i] <= 'F')
            a = liczba[i] - 55;
        else if (liczba[i] >= 'a' && liczba[i] <= 'f')
            a = liczba[i] - 87;
        else {
            cout << "Niepoprawny znak w liczbie" << std::endl;
            exit(1);
        }

        wynik += a * b;
        b *= system;
    }

    return wynik;
}
//wyswietlanie wyniku w okreslonym systemie liczbowym
void wyswietlwynik(int wynik, int system) {
    if (system == 2)
        std::cout << "Wynik w systemie binarnym: " << bitset<32>(wynik) << std::endl;
    else if (system == 8)
        std::cout << "Wynik w systemie osemkowym: " << oct << wynik << std::endl;
    else if (system == 10)
        std::cout << "Wynik w systemie dziesietnym: " << dec << wynik << std::endl;
    else if (system == 16)
        std::cout << "Wynik w systemie szesnastkowym: " << hex << wynik << std::endl;
}
//wybor systemu liczbowego
int wybierzSystem() {
    int wybor;

    std::cout << "Wybierz system liczbowy:" << std::endl;
    std::cout << "1. Binarny" << std::endl;
    std::cout << "2. Osemkowy" << std::endl;
    std::cout << "3. Dziesietny" << std::endl;
    std::cout << "4. Szesnastkowy" << std::endl;

    cin >> wybor;

    switch (wybor) {
    case 1:
        return 2;
    case 2:
        return 8;
    case 3:
        return 10;
    case 4:
        return 16;
    default:
        std::cout << "Niepoprawny wybor!" << std::endl;
        exit(1);
    }
}
//wczytanie i zwrot liczby w wybranym systemie 
int wczytajLiczbe(int system, const char* wiadomosc) {
    char liczba[100];

    std::cout << wiadomosc;
    std::cin >> liczba;

    return dodziesietnego(liczba, system);
}
//wczytanie operacji od uzytkownika
int wczytajOperacje() {
    int wybor;

    std::cout << "Wybierz operacje:" << std::endl;
    std::cout << "1. Dodawanie" << std::endl;
    std::cout << "2. Odejmowanie" << std::endl;
    std::cout << "3. Mnozenie" << std::endl;
    std::cout << "4. Dzielenie" << std::endl;
    std::cout << "5. Potegowanie" << std::endl;
    std::cout << "6. Pierwiastkowanie" << std::endl;

    cin >> wybor;

    return wybor;
}
//wykonanie operacji na 2 liczbach i wyswietlenie wyniku w wybranym systemie liczbowym
void wykonajDzialanie(int liczba1, int liczba2, int system, int wybor) {
    switch (wybor) {
    case 1:
        wyswietlwynik(liczba1 + liczba2, system);
        break;
    case 2:
        wyswietlwynik(liczba1 - liczba2, system);
        break;
    case 3:
        wyswietlwynik(liczba1 * liczba2, system);
        break;
    case 4:
        if (liczba2 != 0) {
            wyswietlwynik(liczba1 / liczba2, system);
        }

        else {
            std::cout << "Nie mozna dzielic przez zero" << std::endl;
        }
        break;
    case 5:
        wyswietlwynik(pow(liczba1, liczba2), system);
        break;
    case 6:
        if (liczba1 >= 0) {
            cout << "Pierwiastek z liczby " << liczba1 << " wynosi " << sqrt(liczba1) << endl;
        }
        else {
            cout << "Nie mozna obliczyć pierwiastka z liczby ujemnej." << std::endl;
        }
        break;
    default:
        std::cout << "Niepoprawny wybór operacji" << std::endl;
        exit(1);
    }
}

int main() {
    //char liczba1[100], liczba2[100];
    int system, wybor, kontynuacja;

    do {
        system = wybierzSystem();
        int liczba1 = wczytajLiczbe(system, "Podaj pierwsza liczbe");
        int liczba2 = wczytajLiczbe(system, "Podaj druga liczbe");

        wybor = wczytajOperacje();

        wykonajDzialanie(liczba1, liczba2, system, wybor);

        std::cout << "Czy chcesz kontynuowac?" << std::endl;
        std::cout << "1- Tak " << std::endl;
        std::cout << "0 -Nie " << std::endl;
        std::cin >> kontynuacja;
    } while (kontynuacja == 1);

    return 0;
}
