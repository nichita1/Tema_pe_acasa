#include <iostream>
#include <string>

using namespace std;
int main() {
    string S;
    cout << "Sir S: ";
    cin >> S;
    cout << "\n Rezultate ";
    int count_A = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'A') {
            count_A++;
        }
    }
    cout << "a) Nr 'A': " << count_A << endl;
    string S_b = S;
    for (int i = 0; i < S_b.length(); i++) {
        if (S_b[i] == 'A') {
            S_b[i] = '*';
        }
    }
    cout << "b) 'A'->'*': " << S_b << endl;
    string S_c = "";
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != 'B') {
            S_c += S[i];
        }
    }
    cout << "c) Fara 'B': " << S_c << endl;
    int count_MA = 0;
    for (int i = 0; i <= S.length() - 2; i++) {
        if (S[i] == 'M' && S[i+1] == 'A') {
            count_MA++;
        }
    }
    cout << "d) Nr 'MA': " << count_MA << endl;
    string S_e = "";
    for (int i = 0; i < S.length(); i++) {
        if (i <= S.length() - 2 && S[i] == 'M' && S[i+1] == 'A') {
            S_e += "TA"; 
            i++;        
        } else {
            S_e += S[i]; 
        }
    }
    cout << "e) 'MA'->'TA': " << S_e << endl;
    string S_f = "";
    for (int i = 0; i < S.length(); i++) {
        if (i <= S.length() - 2 && S[i] == 'T' && S[i+1] == 'O') {
            i++;        
        } else {
            S_f += S[i]; 
        }
    }
    cout << "f) Fara 'TO': " << S_f << endl;
    string S_g = "";
    for (int i = S.length() - 1; i >= 0; i--) {
        S_g += S[i];
    }
    cout << "g) Invers: " << S_g << endl;
    string S_invers = S_g; 
    bool este_palindrom = (S == S_invers);
    cout << "h) Palindrom: " << (este_palindrom ? "true" : "false") << endl;
    string S_i = S;
    for (int i = 0; i < S_i.length(); i++) {
        if (S_i[i] >= 'a' && S_i[i] <= 'z') {
            S_i[i] = S_i[i] - 32;
        }
    }
    cout << "i) Tot Mare: " << S_i << endl;
    string S_j = S;
    if (S_j.length() > 0 && (S_j[0] >= 'a' && S_j[0] <= 'z')) {
         S_j[0] = S_j[0] - 32;
    }
    for (int i = 1; i < S_j.length(); i++) {
        bool is_letter = (S_j[i] >= 'a' && S_j[i] <= 'z') || (S_j[i] >= 'A' && S_j[i] <= 'Z');
        if (S_j[i-1] == ' ' && is_letter) {
            if (S_j[i] >= 'a' && S_j[i] <= 'z') {
                 S_j[i] = S_j[i] - 32;
            }
        }
    }
    cout << "j) Prima Mare: " << S_j << endl;
    string S_k = S;
    int n = S_k.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (S_k[i] > S_k[j]) {
                char temp = S_k[i];
                S_k[i] = S_k[j];
                S_k[j] = temp;
            }
        }
    }
    cout << "k) Sortat: " << S_k << endl;
    return 0;
}