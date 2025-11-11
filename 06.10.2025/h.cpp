#include <iostream>
#include <stdlib.h> 
#include <time.h>   
using namespace std;
int N_MAX = 10; 
int main() {
    srand(time(0)); 
    int N = 5; 
    int lst = 10;
    int ldr = 50;
    int A[N_MAX][N_MAX];
    long long sumaElementeImpare = 0;
    int numarElementeImpare = 0;
    if (N > N_MAX) {
        return 1;
    }
    if (lst > ldr) {
        int temp = lst;
        lst = ldr;
        ldr = temp;
    }
    int interval_marime = ldr - lst + 1;
    if (interval_marime <= 0) interval_marime = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = lst + rand() % interval_marime;
        }
    }
    cout << "Matrice:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; ++i) {
        int j = N - 1 - i; 
        int element = A[i][j];
        if (element % 2 != 0) {
            sumaElementeImpare += element;
            numarElementeImpare++;
        }
    }
    cout << "\nRezultat:\n";
    if (numarElementeImpare == 0) {
        cout << "Media este 0.\n";
    } else {
        double medie = sumaElementeImpare * 1.0 / numarElementeImpare;
        
        cout << "Suma impare: " << sumaElementeImpare << "\n";
        cout << "Nr. impare: " << numarElementeImpare << "\n";
        cout << "Media: " << medie << "\n";
    }
    return 0;
}