#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Melodie {
    string titlu;
    string interpret;
    int puncte;
};

int main() {
    ifstream fin("melodii.txt");
    ofstream fout("top10.txt");

    int n;
    fin >> n;

    vector<Melodie> v(n);

    for (int i = 0; i < n; i++) {
        int acumulate, primite;
        fin >> v[i].titlu;
        fin >> v[i].interpret;
        fin >> acumulate;
        fin >> primite;
        v[i].puncte = acumulate + primite;
    }

    sort(v.begin(), v.end(), [](Melodie a, Melodie b) {
        return a.puncte > b.puncte;
    });

    for (int i = 0; i < 10 && i < n; i++) {
        fout << v[i].titlu << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
