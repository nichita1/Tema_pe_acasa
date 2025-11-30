#include <iostream>
using namespace std;

const int M = 200;

bool contine_cifra_5(int x) {
    if (x < 0) {
        x = -x;
    }
    if (x == 0) {
        return false;
    }
    while (x > 0) {
        if (x % 10 == 5) {
            return true;
        }
        x /= 10;
    }
    return false;
}

int p_c(int x){
    if(x<0){
        x=-x;
    }
    if(x==0){
        return 0;
    }
    while(x>=10){
        x/=10;
    }
    return x;
}

int main(){
    int n, a[M];
    
    cin >> n;
    if (n > M || n < 0) n = M; 

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    int C;
    cin >> C;

    int index_primul_5 = -1;
    for (int i = 0; i < n; ++i) {
        if (contine_cifra_5(a[i])) {
            index_primul_5 = i;
            break;
        }
    }

    if (index_primul_5 != -1) {
        for (int i = index_primul_5; i < n - 1; ++i) {
            a[i] = a[i + 1];
        }
        n--;
        
        cout << "Dupa Cerinta 1:" << endl;
        for(int i = 0; i < n; ++i){
            cout << a[i] << " ";
        }
    } else {
        cout << "Dupa Cerinta 1: Tabloul ramane neschimbat." << endl;
    }
    cout << endl;
    
    int j = 0;
    for(int i = 0; i < n; ++i){
        if(p_c(a[i]) != C){
            a[j] = a[i];
            j++;
        }
    }
    n = j;

    cout << "Dupa Cerinta 2:" << endl;
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
