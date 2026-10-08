#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> rozklad_naiwny(long long n) {
    vector<long long> czynniki;
    long long d = 2;
    while (n > 1) {
        if (n % d == 0) {
            czynniki.push_back(d);
            n /= d;
        } else {
            ++d;
        }
    }
    return czynniki;
}

vector<long long> rozklad(long long n) {
    vector<long long> czynniki;
    long long d = 2;
    while (d * d <= n) {
        while (n % d == 0) {
            czynniki.push_back(d);
            n /= d;
        }
        ++d;
    }

    if (n > 1) {
        czynniki.push_back(n);
    }

    return czynniki;
}

void pokaz(const vector<long long>& liczby) {
    for (long long l: liczby) {
        cout << l << "\t";
    }
    cout << "\n";
} 

bool czy_pierwsza(long long n) {
    if (n < 2) {
        return false;
    }

    long long d = 2;
    while (d * d <= n) {
        if (n % d == 0) {
            return false;
        }
        ++d;
    }
    return true;
}

string postac_potegowa(long long n) {
    string wynik = to_string(n) + " = ";
    string separator = "";
    long long d = 2;

    while (d * d <= n) {
        int wykladnik = 0;
        while (n % d == 0) {
            ++wykladnik;
            n /= d;
        }
        if (wykladnik > 0) {
            wynik += separator + to_string(d);
            if (wykladnik > 1) {
                wynik += "^" + to_string(wykladnik);
            }
            separator = " * ";
        }
        ++d;
    }

    if (n > 1) {
        wynik += separator + to_string(n);
    }

    return wynik;
}

int main() {
    long long n = 420;
    vector<long long> czynniki_1 = rozklad_naiwny(n);
    vector<long long> czynniki_2 = rozklad(n);
    pokaz(czynniki_1);
    pokaz(czynniki_2);
    cout << "Czy pierwsza: 97 = " << czy_pierwsza(97) << "\n";
    cout << "Czy pierwsza: 91 = " << czy_pierwsza(91) << "\n";
    cout << postac_potegowa(n) << "\n";
    cout << postac_potegowa(99792) << "\n";

    return 0;
}