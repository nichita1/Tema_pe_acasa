#include <iostream>
using namespace std;

int main(){
    const int M=100;
    int n; 
    int mat[M][M];
    cin>>n; 
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {

            cin>>mat[i][j];
        }
    }
    int suma=0;
    int contor=0;
    for(int i=0;i<n;++i)
    {
        int j=n-1-i;
        if(mat[i][j]%2!=0){
            suma+=mat[i][j];
            contor++;
        }
    }
    if(contor>0){
        int media=suma/contor;
        cout<<media<<endl;
    }else{
        cout<<"Nu exista elemente impare pe diagonala secundara."<<endl;
    }
    return 0;
}