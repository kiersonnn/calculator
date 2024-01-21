#include "gtest/gtest.h"
#include "pch.h"
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;

bool poprawnoscbinarny(const char liczba[]) {
    for (int i = 0; i < strlen(liczba); i++) {
        if (liczba[i] != '0' && liczba[i] != '1') {
            return false;
        }
    }
    return true;
}

bool poprawnoscbinarny(const char liczba[]);

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
          //  std::cout << "Niepoprawny znak w liczbie" << std::endl;
            exit(1);
        }

        wynik += a * b;
        b *= system;
    }

    return wynik;
}

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
            std::cout << "Pierwiastek z liczby " << liczba1 << " wynosi " << sqrt(liczba1) << std::endl;
        }
        else {
            std::cout << "Nie mozna obliczyæ pierwiastka z liczby ujemnej." << std::endl;
        }
        break;
    default:
        std::cout << "Niepoprawny wybór operacji" << std::endl;
        exit(1);
    }
}

//Sprawdzanie poprawnosci binarnego
TEST(PoprawnoscBinarnyTest, PoprawnaLiczbaBinarna) {
    const char* liczba = "1010101";
    EXPECT_TRUE(poprawnoscbinarny(liczba));
}

TEST(PoprawnoscBinarnyTest, NiePoprawnaLiczbaBinarna) {
    const char* liczba = "1020101";
    EXPECT_FALSE(poprawnoscbinarny(liczba));
}

//Sprawdzanie konwersji do dziesietnego

TEST(DodziesietnegoTest, KonwersjaZBinarnego) {
    const char* liczba = "1010";
    EXPECT_TRUE(dodziesietnego(liczba, 2), 10);
}



TEST(DodziesietnegoTest, KonwersjaZSzesnastkowego) {
    const char* liczba = "14";
    EXPECT_TRUE(dodziesietnego(liczba, 16), 20);
}


TEST(DodziesietnegoTest, KonwersjaZOsemkowego) {
    const char* liczba = "11";
    EXPECT_TRUE(dodziesietnego(liczba, 8), 9);
}




//Testowanie dzialan
//dziesietny
TEST(WykonajDzialanieTest, Potegowanie10) {
    EXPECT_TRUE(16, wykonajDzialanie(2, 4, 10, 5));
}
//binarny
TEST(WykonajDzialanieTest, Potegowanie2) {
    EXPECT_TRUE(1000, wykonajDzialanie(10, 100, 2, 5));
}
//osemkowy
TEST(WykonajDzialanieTest, Potegowanie8) {
    EXPECT_TRUE(20, wykonajDzialanie(2, 4, 8, 5));
}
//szesnastkowy
TEST(WykonajDzialanieTest, Potegowanie16) {
    EXPECT_TRUE(10, wykonajDzialanie(2, 4, 16, 5));
}

//dziesietny
TEST(WykonajDzialanieTest, Dodawanie10) {
    EXPECT_TRUE(6, wykonajDzialanie(2, 4, 10, 1));
}
//binarny
TEST(WykonajDzialanieTest, Dodawanie2) {
    EXPECT_TRUE(110, wykonajDzialanie(10, 100, 2, 1));
}
//osemkowy
TEST(WykonajDzialanieTest, Dodawanie8) {
    EXPECT_TRUE(6, wykonajDzialanie(2, 4, 8, 1));
}
//szesnastkowy
TEST(WykonajDzialanieTest, Dodawanie16) {
    EXPECT_TRUE(6, wykonajDzialanie(2, 4, 16, 1));
}

//dziesietny
TEST(WykonajDzialanieTest, Odejmowanie10) {
    EXPECT_TRUE(2, wykonajDzialanie(6, 4, 10, 2));
}
//binarny
TEST(WykonajDzialanieTest, Odejmowanie2) {
    EXPECT_TRUE(10, wykonajDzialanie(110, 100, 2, 2));
}
//osemkowy
TEST(WykonajDzialanieTest, Odejmowanie8) {
    EXPECT_TRUE(2, wykonajDzialanie(6, 4, 8, 2));
}
//szesnastkowy
TEST(WykonajDzialanieTest, Odejmowanie16) {
    EXPECT_TRUE(2, wykonajDzialanie(6, 4, 16, 2));
}

//dziesietny
TEST(WykonajDzialanieTest, Mnozenie10) {
    EXPECT_TRUE(8, wykonajDzialanie(2, 4, 10, 3));
}
//binarny
TEST(WykonajDzialanieTest, Mnozenie2) {
    EXPECT_TRUE(1000, wykonajDzialanie(10, 100, 2, 3));
}
//osemkowy
TEST(WykonajDzialanieTest, Mnozenie8) {
    EXPECT_TRUE(10, wykonajDzialanie(2, 4, 8, 3));
}
//szesnastkowy
TEST(WykonajDzialanieTest, Mnozenie16) {
    EXPECT_TRUE(8, wykonajDzialanie(2, 4, 16, 3));
}
//dziesietny
TEST(WykonajDzialanieTest, Dzielenie10) {
    EXPECT_TRUE(2, wykonajDzialanie(8, 4, 10, 4));
}
//binarny
TEST(WykonajDzialanieTest, Dzielenie2) {
    EXPECT_TRUE(10, wykonajDzialanie(100, 10, 2, 4));
}
//osemkowy
TEST(WykonajDzialanieTest, Dzielenie8) {
    EXPECT_TRUE(2, wykonajDzialanie(6, 3, 8, 4));
}
//szesnastkowy
TEST(WykonajDzialanieTest, Dzielenie16) {
    EXPECT_TRUE(2, wykonajDzialanie(6, 3, 16, 4));
}

//dziesietny
TEST(WykonajDzialanieTest, Pierwiastek10) {
    EXPECT_TRUE(3, wykonajDzialanie(9, 0, 10, 6));
}
//binarny
TEST(WykonajDzialanieTest, Pierwiastek2) {
    EXPECT_TRUE(10, wykonajDzialanie(100, 0, 2, 6));
}
//osemkowy
TEST(WykonajDzialanieTest, Pierwiastek8) {
    EXPECT_TRUE(2, wykonajDzialanie(4, 0, 8, 6));
}
//szesnastkowy
TEST(WykonajDzialanieTest, Pierwiastek16) {
    EXPECT_TRUE(4, wykonajDzialanie(20, 0, 16, 6));
}
