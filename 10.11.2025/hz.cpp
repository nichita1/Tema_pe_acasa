#include <iostream>

using namespace std;

int main() {
    int N = 10; 
    char A[N];
    char B[N];
    
    int nA = N; 
    int nB = N; 
    
    cout << "Introdu " << N << " caractere pentru A:\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << "Introdu " << N << " caractere pentru B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    cout << "\nRezultate:\n";
    
    char Reuniune[N * 2]; 
    int nR = 0; 

    for (int i = 0; i < nA; i++) {
        Reuniune[nR++] = A[i];
    }

    for (int j = 0; j < nB; j++) {
        bool gasit_in_A = false;
        for (int i = 0; i < nA; i++) {
            if (A[i] == B[j]) {
                gasit_in_A = true;
                break;
            }
        }
        
        if (!gasit_in_A) {
            Reuniune[nR++] = B[j];
        }
    }
    
    char Intersectie[N]; 
    int nI = 0; 

    for (int i = 0; i < nA; i++) {
        bool gasit_in_B = false;
        for (int j = 0; j < nB; j++) {
            if (B[j] == A[i]) {
                gasit_in_B = true;
                break;
            }
        }
        
        if (gasit_in_B) {
            Intersectie[nI++] = A[i];
        }
    }

    char Diferenta1[N]; 
    int nD1 = 0;

    for (int i = 0; i < nA; i++) {
        bool gasit_in_B = false;
        for (int j = 0; j < nB; j++) {
            if (B[j] == A[i]) {
                gasit_in_B = true;
                break;
            }
        }
        
        if (!gasit_in_B) {
            Diferenta1[nD1++] = A[i];
        }
    }

    char Diferenta2[N]; 
    int nD2 = 0;

    for (int j = 0; j < nB; j++) {
        bool gasit_in_A = false;
        for (int i = 0; i < nA; i++) {
            if (A[i] == B[j]) {
                gasit_in_A = true;
                break;
            }
        }
        
        if (!gasit_in_A) {
            Diferenta2[nD2++] = B[j];
        }
    }

    cout << "1. Reuniunea = { ";
    for (int i = 0; i < nR; i++) cout << Reuniune[i] << (i < nR - 1 ? ", " : "");
    cout << " }\n";

    cout << "2. Intersectia = { ";
    for (int i = 0; i < nI; i++) cout << Intersectie[i] << (i < nI - 1 ? ", " : "");
    cout << " }\n";
    
    cout << "3. Diferenta A\\B = { ";
    for (int i = 0; i < nD1; i++) cout << Diferenta1[i] << (i < nD1 - 1 ? ", " : "");
    cout << " }\n";

    cout << "4. Diferenta B\\A = { ";
    for (int i = 0; i < nD2; i++) cout << Diferenta2[i] << (i < nD2 - 1 ? ", " : "");
    cout << " }\n";
    
    return 0;
}