#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int matricola;
    string nume;
    string prenume;
    int mate[3];
    int fiz[3];
    int info[3];
};

/* functii pentru medii */
float medieMaterie(int v[3]) {
    return (v[0] + v[1] + v[2]) / 3.0f;
}

float medieGenerala(Student s) {
    return (medieMaterie(s.mate) +
            medieMaterie(s.fiz) +
            medieMaterie(s.info)) / 3.0f;
}

/* functii de comparare pentru sortare */
bool cmpMatricola(Student a, Student b) {
    return a.matricola < b.matricola;
}

bool cmpMedie(Student a, Student b) {
    return medieGenerala(a) < medieGenerala(b);
}

bool cmpNume(Student a, Student b) {
    return a.nume < b.nume;
}

int main() {
    vector<Student> v;
    int opt;

    do {
        cout << "\n----- MENIU -----\n";
        cout << "1. Creare fisier studenti\n";
        cout << "2. Afisare studenti\n";
        cout << "3. Statistica medii\n";
        cout << "4. Studenti cu cel putin un examen nepromovat\n";
        cout << "5. Afisare studenti ordonati dupa matricola\n";
        cout << "6. Studenti cu media generala > 5\n";
        cout << "7. Studenti cu media generala < 5\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> opt;

        /* 1. creare fisier */
        if (opt == 1) {
            ofstream fout("studenti.txt");
            int n;
            cout << "Numar studenti: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                Student s;
                cout << "Matricola Nume Prenume:\n";
                cin >> s.matricola >> s.nume >> s.prenume;

                cout << "Note Matematica (3): ";
                for (int j = 0; j < 3; j++)
                    cin >> s.mate[j];

                cout << "Note Fizica (3): ";
                for (int j = 0; j < 3; j++)
                    cin >> s.fiz[j];

                cout << "Note Informatica (3): ";
                for (int j = 0; j < 3; j++)
                    cin >> s.info[j];

                fout << s.matricola << " "
                     << s.nume << " "
                     << s.prenume << " ";

                for (int j = 0; j < 3; j++) fout << s.mate[j] << " ";
                for (int j = 0; j < 3; j++) fout << s.fiz[j] << " ";
                for (int j = 0; j < 3; j++) fout << s.info[j] << " ";

                fout << "\n";
            }
            fout.close();
            cout << "Fisier creat cu succes!\n";
        }

        /* citire fisier pentru restul optiunilor */
        if (opt >= 2) {
            ifstream fin("studenti.txt");
            v.clear();
            Student s;

            while (fin >> s.matricola >> s.nume >> s.prenume) {
                for (int j = 0; j < 3; j++) fin >> s.mate[j];
                for (int j = 0; j < 3; j++) fin >> s.fiz[j];
                for (int j = 0; j < 3; j++) fin >> s.info[j];
                v.push_back(s);
            }
            fin.close();
        }

        /* 2. afisare studenti */
        if (opt == 2) {
            for (int i = 0; i < v.size(); i++) {
                Student s = v[i];
                cout << s.matricola << " "
                     << s.nume << " "
                     << s.prenume << endl;
            }
        }

        /* 3. statistica medii */
        if (opt == 3) {
            int a = 0, b = 0, c = 0, d = 0;
            for (int i = 0; i < v.size(); i++) {
                float m = medieGenerala(v[i]);
                if (m < 4) a++;
                else if (m <= 6) b++;
                else if (m <= 8) c++;
                else d++;
            }
            cout << "Sub 4.00: " << a << endl;
            cout << "4.01 - 6.00: " << b << endl;
            cout << "6.01 - 8.00: " << c << endl;
            cout << "8.01 - 10.00: " << d << endl;
        }

        /* 4. studenti cu restante */
        if (opt == 4) {
            int cnt = 0;
            for (int i = 0; i < v.size(); i++) {
                bool restanta = false;
                for (int j = 0; j < 3; j++)
if (v[i].mate[j] < 5 ||
                        v[i].fiz[j] < 5 ||
                        v[i].info[j] < 5)
                        restanta = true;
                if (restanta) cnt++;
            }
            cout << "Studenti cu cel putin un examen nepromovat: "
                 << cnt << endl;
        }

        /* 5. sortare dupa matricola */
        if (opt == 5) {
            sort(v.begin(), v.end(), cmpMatricola);
            for (int i = 0; i < v.size(); i++) {
                cout << v[i].matricola << " "
                     << v[i].nume << " "
                     << v[i].prenume << endl;
            }
        }

        /* 6. studenti cu media > 5 */
        if (opt == 6) {
            vector<Student> r;
            for (int i = 0; i < v.size(); i++)
                if (medieGenerala(v[i]) > 5)
                    r.push_back(v[i]);

            sort(r.begin(), r.end(), cmpMedie);

            for (int i = 0; i < r.size(); i++)
                cout << r[i].nume << " "
                     << r[i].prenume << " "
                     << medieGenerala(r[i]) << endl;
        }

        /* 7. studenti cu media < 5 */
        if (opt == 7) {
            vector<Student> r;
            for (int i = 0; i < v.size(); i++)
                if (medieGenerala(v[i]) < 5)
                    r.push_back(v[i]);

            sort(r.begin(), r.end(), cmpNume);

            for (int i = 0; i < r.size(); i++)
                cout << r[i].nume << " "
                     << r[i].prenume << " "
                     << medieGenerala(r[i]) << endl;
        }

    } while (opt != 0);

    return 0;
}
