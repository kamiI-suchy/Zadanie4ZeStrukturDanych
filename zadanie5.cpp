#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double Re, Im;
public:
    Complex() : Re(0), Im(0) {}
    Complex(double InRe, double InIm) : Re(InRe), Im(InIm) {}

    // Operator unarny - (sprzezenie liczby zespolonej) - funkcja skladowa klasy
    Complex operator-() const {
        return Complex(Re, -Im);
    }

    // Operatory arytmetyczne binarne - funkcje zaprzyjaznione
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);

    // Operatory wejscia i wyjscia
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);

    // Funkcja obliczajaca modul liczby zespolonej
    friend double Module(const Complex& c);
};

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.Re + b.Re, a.Im + b.Im);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.Re - b.Re, a.Im - b.Im);
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.Re * b.Re - a.Im * b.Im,
                   a.Re * b.Im + a.Im * b.Re);
}

Complex operator/(const Complex& a, const Complex& b) {
    double denom = b.Re * b.Re + b.Im * b.Im;
    return Complex((a.Re * b.Re + a.Im * b.Im) / denom,
                   (a.Im * b.Re - a.Re * b.Im) / denom);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.Re;
    if (c.Im >= 0)
        out << "+" << c.Im << "i";
    else
        out << c.Im << "i";
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    cout << "Podaj czesc rzeczywista: ";
    in >> c.Re;
    cout << "Podaj czesc urojona: ";
    in >> c.Im;
    return in;
}

double Module(const Complex& c) {
    return sqrt(c.Re * c.Re + c.Im * c.Im);
}

int main() {
    Complex z1(3, 4);
    Complex z2(1, -2);

    cout << "=== Obiekty ===" << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;

    cout << "=== Operatory arytmetyczne ===" << endl;
    cout << "z1 + z2 = " << (z1 + z2) << endl;
    cout << "z1 - z2 = " << (z1 - z2) << endl;
    cout << "z1 * z2 = " << (z1 * z2) << endl;
    cout << "z1 / z2 = " << (z1 / z2) << endl;
    cout << endl;

    cout << "=== Operator unarny - (sprzezenie) ===" << endl;
    cout << "Sprzezenie z1 = " << (-z1) << endl;
    cout << "Sprzezenie z2 = " << (-z2) << endl;
    cout << endl;

    cout << "=== Modul ===" << endl;
    cout << "Module(z1) = " << Module(z1) << endl;
    cout << "Module(z2) = " << Module(z2) << endl;
    cout << endl;

    cout << "=== Wczytywanie ===" << endl;
    Complex z3;
    cin >> z3;
    cout << "Wczytano: " << z3 << endl;

    return 0;
}
