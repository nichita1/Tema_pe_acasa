#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_N = 10;
const int SUCCES = 1;

struct Punct {
    double x, y;
};

struct Triunghi {
    Punct v1, v2, v3;
    double a, b, c;
    double aria;
};

double distanta(Punct p1, Punct p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calculeazaAriaHeron(double a, double b, double c) {
    if (a + b <= c  a + c <= b  b + c <= a) {
        return 0.0;
    }
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triunghi citesteTriunghi() {
    Triunghi t;
    cout << "Introduceti coordonatele varfului 1 (x y): ";
    cin >> t.v1.x >> t.v1.y;
    cout << "Introduceti coordonatele varfului 2 (x y): ";
    cin >> t.v2.x >> t.v2.y;
    cout << "Introduceti coordonatele varfului 3 (x y): ";
    cin >> t.v3.x >> t.v3.y;

    t.a = distanta(t.v2, t.v3);
    t.b = distanta(t.v1, t.v3);
    t.c = distanta(t.v1, t.v2);

    t.aria = calculeazaAriaHeron(t.a, t.b, t.c);
    
    if (t.aria == 0.0) {
        cout << "ATENTIE: Triunghi invalid (posibil coliniar sau degenerat)." << endl;
    }
    
    return t;
}

// Returneaza un int (indicator de succes) in locul lui void
int afiseazaTriunghi(const Triunghi& t) {
    cout << "V1(" << t.v1.x << ", " << t.v1.y << ") ";
    cout << "V2(" << t.v2.x << ", " << t.v2.y << ") ";
    cout << "V3(" << t.v3.x << ", " << t.v3.y << ") ";
    cout << "| Aria: " << fixed << setprecision(4) << t.aria;
    cout << endl;
    
    return SUCCES;
}

int main() {
    cout << fixed << setprecision(4);

    int n;
    cout << "Introduceti numarul de triunghiuri (n <= 10): ";
    cin >> n;

    if (n <= 0 || n > MAX_N) {
        cout << "Numar invalid de triunghiuri. Programul se incheie." << endl;
        return 1;
    }

    Triunghi triunghiuri[MAX_N]; 

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Citirea triunghiului " << i + 1 << " ---" << endl;
        triunghiuri[i] = citesteTriunghi();
    }

    cout << "\n========================================" << endl;
    cout << "a) Aria fiecarui triunghi:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Triunghiul " << i + 1 << ": Aria = " << triunghiuri[i].aria << endl;
    }
    
    if (n > 0) {
        int max_index = 0;
        int min_index = 0;

        for (int i = 1; i < n; ++i) {
            if (triunghiuri[i].aria > triunghiuri[max_index].aria) {
                max_index = i;
            }
            if (triunghiuri[i].aria < triunghiuri[min_index].aria) {
                min_index = i;
            }
        }

        cout << "\n========================================" << endl;
        cout << "b) Coordonatele varfurilor triunghiului cu aria MAXIMA:" << endl;
        afiseazaTriunghi(triunghiuri[max_index]);

        cout << "\n========================================" << endl;
        cout << "c) Coordonatele varfurilor triunghiului cu aria MINIMA:" << endl;
        afiseazaTriunghi(triunghiuri[min_index]);
    }
    
    cout << "\n========================================" << endl;
    cout << "d) Triunghiurile in ordinea cresterii ariilor (sortate):" << endl;

    // Sortarea in interiorul main (Bubble Sort)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (triunghiuri[j].aria > triunghiuri[j + 1].aria) {
                Triunghi temp = triunghiuri[j];
                triunghiuri[j] = triunghiuri[j + 1];
                triunghiuri[j + 1] = temp;
            }
        }
    }
return 0;
}
    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << ". ";
        afiseazaTriunghi(triunghiuri[i]);
    }
