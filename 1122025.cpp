#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("DATE.IN");
    if (!fin.is_open()) {
        return 1;
    }

    long long a, b, c;
    int contor_poli = 0;

    if (!(fin >> a >> b)) {
        cout << 0 << endl;
        fin.close();
        return 0;
    }

    while (fin >> c) {
        if (b > a && b > c) {
            contor_poli++;
        }
        
        a = b;
        b = c;
    }

    fin.close();

    cout << contor_poli << endl;

    return 0;
}
