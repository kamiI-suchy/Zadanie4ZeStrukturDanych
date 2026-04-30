#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double X, Y;
    Point() : X(0), Y(0) {}
    Point(double X, double Y) : X(X), Y(Y) {}
};

class Circle {
private:
    Point Centre;
    double Radius;
public:
    Circle(double X, double Y, double R) : Centre(X, Y), Radius(R) {}

    void Print() {
        cout << "Okrag: srodek=(" << Centre.X << ", " << Centre.Y
             << "), promien=" << Radius << endl;
    }

    // Zadanie 1
    friend void PrintQuadrant(const Circle& C);

    // Zadanie 2
    friend bool CircleCompare(const Circle& C1, const Circle& C2);
    friend Circle CircleAdd(const Circle& C1, const Circle& C2);

    // Zadanie 3
    friend bool operator>(const Circle& C1, const Circle& C2);
    friend Circle operator+(const Circle& C1, const Circle& C2);
};


// ZADANIE 1 - funkcja zaprzyjazniona drukujaca informacje o cwiartkach

void PrintQuadrant(const Circle& C) {
    double x = C.Centre.X;
    double y = C.Centre.Y;
    double r = C.Radius;

    double lewy  = x - r;
    double prawy = x + r;
    double dolny = y - r;
    double gorny = y + r;

    bool q1 = prawy > 0 && gorny > 0;
    bool q2 = lewy  < 0 && gorny > 0;
    bool q3 = lewy  < 0 && dolny < 0;
    bool q4 = prawy > 0 && dolny < 0;

    cout << "Okrag: srodek=(" << x << ", " << y << "), promien=" << r << endl;
    cout << "Okrag lezy w cwiartkach: ";
    if (q1) cout << "I ";
    if (q2) cout << "II ";
    if (q3) cout << "III ";
    if (q4) cout << "IV ";
    cout << endl << endl;
}


// ZADANIE 2 - funkcje zaprzyjaznione CircleCompare i CircleAdd

bool CircleCompare(const Circle& C1, const Circle& C2) {
    return C1.Radius > C2.Radius;
}

Circle CircleAdd(const Circle& C1, const Circle& C2) {
    return Circle(C1.Centre.X, C1.Centre.Y, C1.Radius + C2.Radius);
}


// ZADANIE 3 - przeciazenie operatorow > i +

bool operator>(const Circle& C1, const Circle& C2) {
    return C1.Radius > C2.Radius;
}

Circle operator+(const Circle& C1, const Circle& C2) {
    return Circle(C1.Centre.X, C1.Centre.Y, C1.Radius + C2.Radius);
}


// MAIN

int main() {
    Circle c1(3, 3, 5);
    Circle c2(1, 1, 2);
    Circle c3(-4, -4, 3);
    Circle c4(0, 0, 7);

    cout << "=== Obiekty ===" << endl;
    c1.Print();
    c2.Print();
    c3.Print();
    c4.Print();
    cout << endl;

    // --- Zadanie 1 ---
    cout << "=== ZADANIE 1 - Cwwiartki ===" << endl;
    PrintQuadrant(c1);
    PrintQuadrant(c2);
    PrintQuadrant(c3);
    PrintQuadrant(c4);

    // --- Zadanie 2 ---
    cout << "=== ZADANIE 2 - CircleCompare i CircleAdd ===" << endl;

    cout << "CircleCompare(c1, c2): ";
    if (CircleCompare(c1, c2))
        cout << "c1 ma WIEKSZY promien niz c2" << endl;
    else
        cout << "c1 NIE ma wiekszego promienia niz c2" << endl;

    cout << "CircleCompare(c2, c3): ";
    if (CircleCompare(c2, c3))
        cout << "c2 ma WIEKSZY promien niz c3" << endl;
    else
        cout << "c2 NIE ma wiekszego promienia niz c3" << endl;

    cout << endl;

    Circle wynik1 = CircleAdd(c1, c2);
    cout << "CircleAdd(c1, c2) = "; wynik1.Print();

    Circle wynik2 = CircleAdd(c2, c3);
    cout << "CircleAdd(c2, c3) = "; wynik2.Print();

    cout << endl;

    // --- Zadanie 3 ---
    cout << "=== ZADANIE 3 - Operatory > i + ===" << endl;

    cout << "c1 > c2: ";
    if (c1 > c2)
        cout << "c1 ma WIEKSZY promien niz c2" << endl;
    else
        cout << "c1 NIE ma wiekszego promienia niz c2" << endl;

    cout << "c2 > c3: ";
    if (c2 > c3)
        cout << "c2 ma WIEKSZY promien niz c3" << endl;
    else
        cout << "c2 NIE ma wiekszego promienia niz c3" << endl;

    cout << endl;

    Circle wynik3 = c1 + c2;
    cout << "c1 + c2 = "; wynik3.Print();

    Circle wynik4 = c2 + c3;
    cout << "c2 + c3 = "; wynik4.Print();

    Circle wynik5 = c1 + c2 + c3;
    cout << "c1 + c2 + c3 = "; wynik5.Print();

    return 0;
}
