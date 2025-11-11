#include <iostream>
using namespace std;

int main(){
    const int MAX_SIZE=100;
    int n;
    int a[MAX_SIZE];
    cin>>n; 
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int ultimul_element=0; 
    bool gasit_p1=false;
    for(int i=n-1;i>=0;--i){
        if(a[i]>x){
            ultimul_element=a[i];
            gasit_p1=true;
            break;
        }
    }
    if(gasit_p1){
        cout<<ultimul_element<<endl;
    }else{
        cout<<"Nu exista"<<endl;
    }
    int min_impar=2000000000; 
    int indice_min=-99;
    for(int i=0;i<n;++i){
        if(a[i]%2!=0){
            if(a[i]<=min_impar){
                min_impar=a[i];
                indice_min=i;
            }
        }
    }
    if(indice_min==-99){
        cout<<"Nu exista elemente impare"<<endl;
    }else{
        cout<<min_impar<<" "<<indice_min<<endl;
    }
    return 0;
}