#include <iostream>
#include <cmath>
using namespace std;

class Rational {
private:
    int Licznik, Mianownik;
public:
    Rational(int A = 1, int B = 1) {
        Licznik = A;
        Mianownik = B;
    }

    // Przeciazenie operatora + jako funkcja skladowa klasy
    Rational operator+(const Rational& U) const {
        Rational Wynik;
        Wynik.Licznik = U.Mianownik * Licznik + Mianownik * U.Licznik;
        Wynik.Mianownik = U.Mianownik * Mianownik;
        return Wynik;
    }

    // Przeciazenie operatora << - drukuje ulamek wlasciwy z wylacznymi calosciami
    // np. 10/3  ->  3 1/3
    // np. 1/2   ->  1/2
    // np. 6/2   ->  3
    friend ostream& operator<<(ostream& out, Rational& W);

    friend Rational operator-(const Rational&, const Rational&);
};

ostream& operator<<(ostream& out, Rational& W) {
    int whole     = W.Licznik / W.Mianownik;
    int remainder = W.Licznik % W.Mianownik;

    if (remainder == 0) {
        out << whole;
    } else if (whole != 0) {
        out << whole << " " << remainder << "/" << W.Mianownik;
    } else {
        out << W.Licznik << "/" << W.Mianownik;
    }
    return out;
}

Rational operator-(const Rational& U1, const Rational& U2) {
    Rational Wynik;
    Wynik.Licznik = U2.Mianownik * U1.Licznik - U1.Mianownik * U2.Licznik;
    Wynik.Mianownik = U1.Mianownik * U2.Mianownik;
    return Wynik;
}

int main() {
    Rational r1(10, 3);  // 10/3 = 3 1/3
    Rational r2(1, 2);   // 1/2
    Rational r3(7, 4);   // 7/4 = 1 3/4
    Rational r4(6, 2);   // 6/2 = 3

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;
    cout << "r4 = " << r4 << endl;
    cout << endl;

    Rational sum = r1 + r2;
    cout << "r1 + r2 = " << sum << endl;

    Rational diff = r1 - r2;
    cout << "r1 - r2 = " << diff << endl;

    Rational sum2 = r2 + r3;
    cout << "r2 + r3 = " << sum2 << endl;

    return 0;
}
