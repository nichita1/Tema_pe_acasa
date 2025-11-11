#include <iostream>
#include <cmath>
using namespace std;

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

bool id_c(int x){
    if(x<0){
        x=-x;
    }
    if(x<10){
        return true;
    }
    int u=x%10;
    x/=10;
    while(x>0){
        if(x%10!=u){
            return false;
        }
        x/=10;
    }
    return true;
}

int main(){
    const int M=200;
    int n,a[M];
    
    cin>>n; 
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int C;
    cin>>C;
    int B;
    cin>>B;

    // Problema 2: Eliminare numere care incep cu cifra C
    
    int j=0;
    for(int i=0;i<n;++i){
        if(p_c(a[i])!=C){
            a[j]=a[i];
            j++;
        }
    }
    n=j;
    
    // Afisare dupa P2
    cout<<"Dupa eliminare (P2):"<<endl;
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // Problema 3: Inserare numar B dupa fiecare numar format din cifre identice
    
    int i=0;
    while(i<n){
        if(id_c(a[i])){
            for(j=n;j>i+1;--j){
                a[j]=a[j-1];
            }
            
            a[i+1]=B;
            n++;
            i+=2;
        }else{
            i++;
        }
    }

    // Afisare dupa P3
    cout<<"Dupa inserare (P3):"<<endl;
    for(int k=0;k<n;++k){
        cout<<a[k]<<" ";
    }
    
  }
    cout<<endl;
    return 0;
}