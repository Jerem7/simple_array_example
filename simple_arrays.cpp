// Autor: Jeremiasz Zolnierek-Kielczewski

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <random>

using namespace std;

void menu(), zad1(), zad2(), zad3(), zad4(), errormsg(), powrot_menu();
int menuwybor, wybor;
float odchyl_std_obl(int *, float);
bool powt_menu = true;

int main()
{
    while (powt_menu)
    {
        menu();

        cin >> menuwybor;

        switch (menuwybor)
        {
        case 1:
            zad1();
            powrot_menu();
            break;
        case 2:
            zad2();
            powrot_menu();
            break;
        case 3:
            zad3();
            powrot_menu();
            break;
        case 4:
            zad4();
            powrot_menu();
            break;
        case 5:
            exit(0);
            break;
        default:
            errormsg();
            break;
        }
    }
    return (0);
}
void menu()
{
    cout << "Prosze wybrac odpowiedni numer dla obliczenia ktore ma byc wykonane:\n";
    cout << "1. Zadanie 1. Suma elemntow tablicy Y 8-elementowej wiekszych od zera oraz srednia arytmentyczna elementow mniejszych od zera\n";
    cout << "2. Zadanie 2. Wczytanie z klawiatury elemntów tablicy A 10-elementowej oraz obliczyc element minimalny oraz podac ile razy on wystapil w tablicy\n";
    cout << "3. Zadanie 3. Wczytac liczbe i sprawdzic czy podana liczba wystepuje w tablicy x 15-elementowej, oraz jezeli tak, ile razy\n";
    cout << "4. Zadanie 4. Obliczenie i zwrocenie odchylenia standardowego od sredniej arytm. danych z tablicy X 15-elementowej ktorej elementy sa losowane z przedzialu <p,k>\n";
    cout << "5. Wyjscie z programu\n";
}
void errormsg()
{
    cout << "blednie wybrana, opcja, prosze wybrac ponownie\n";
}
void powrot_menu()
{
    while (true)
    {
        int wybor;
        cout << "\nAby wrocic do MENU, wybierz 1, aby zakonczyc program, wybierz 0.\n";
        cin >> wybor;

        if (wybor == 0)
        {
            // jeśli użytkownik wybrał 1, zamknij program
            exit(0);
        }
        else if (wybor == 1)
        {
            // jeśli użytkownik wybrał 2, kontynuuj program
            break;
        }
        else
        {
            // jeśli użytkownik wprowadził inną wartość, wyświetl komunikat o błędzie
            errormsg();
        }
    }
}

void zad1()
{
    int Y[8];
    int i, suma = 0, suma_ujemne = 0, licznik_ujemne = 0;
    float srednia_ujemne;

    cout << "wprowadz elementy tablicy (pojedynczo, naciskajac enter miedzy kolejnymi elementami)\n";
    for (int i = 0; i < 8; i++)
    {
        cin >> Y[i];
        if (Y[i] > 0)
        {
            suma += Y[i];
        }
        else if (Y[i] < 0)
        {
            suma_ujemne += Y[i];
            licznik_ujemne++;
        }
    }
    if (licznik_ujemne > 0)
        srednia_ujemne = (float)suma_ujemne / licznik_ujemne;
    else
        srednia_ujemne = 0.0;
    cout << "suma liczb pozytywnych to " << suma << " a srednia arytmetyczna ujemnych to " << srednia_ujemne << "\n";
}
void zad2()
{
    int A[10], element_min = INT_MAX, count = 0;
    cout << "wprowadz elementy tablicy (pojedynczo, naciskajac enter miedzy kolejnymi elementami)\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> A[i];
        if (A[i] < element_min)
        {
            element_min = A[i];
            count = 1;
        }
        else if (A[i] == element_min)
            count++;
    }
    cout << "Minimalny element: " << element_min << "\n";
    cout << "Ilosc minimalnego elementu: " << count << "\n";
}
void zad3()
{
    int X[15], liczba_spr;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(5, 30);

    for (int i = 0; i < 15; i++)
    {
        X[i] = dis(gen);
    }

    cout << "Podaj liczbe do sprawdzenia: ";
    cin >> liczba_spr;

    int count = 0;
    for (int i = 0; i < 15; i++)
    {
        if (X[i] == liczba_spr)
        {
            count++;
        }
    }

    if (count > 0)
    {
        cout << "Liczba " << liczba_spr << " wystepuje w tablicy " << count << " razy."
             << "\n";
    }
    else
    {
        cout << "Liczba " << liczba_spr << " nie wystepuje w tablicy."
             << "\n";
    }
    cout << "Elementy tablicy: ";
    for (int i = 0; i < 15; i++)
    {
        cout << X[i] << " ";
    }
    cout << "\n";
}
void zad4()
{
    int X[15];
    int p, k;
    float suma = 0;

    cout << "Wprowadz p: ";
    cin >> p;
    cout << "Wprowadz k: ";
    cin >> k;

    for (int i = 0; i < 15; i++)
    {
        X[i] = rand() % (k - p + 1) + p;
        suma += X[i];
    }
    float odchylenie_std = odchyl_std_obl(X, suma);
    cout << "Odchylenie standardowe: " << odchylenie_std << endl;
}
float odchyl_std_obl(int X[], float suma)
{

    float sigma = 0;
    float sr = suma / 15;

    for (int i = 0; i < 14; i++)
        sigma += ((X[i] - sr) * (X[i] - sr));
    sigma *= 1.0 / 15;
    sigma = sqrt(sigma);

    return sigma;
}