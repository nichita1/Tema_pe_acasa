//exercitiul--7.
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    struct Punct {
    double x;
    double y;
};
Punct P[30];
int i , j , d , n;
cout<<"nr de puncte:"<<endl;
cin>>n;
    for(int i1=0;i1<n;i1++){
cout<<"punct["<<i1<<"]"<<endl;
cout<<"coord x:";
cin>>P[i1].x;
cout<<"coord y:";
cin>>P[i1].y;
    }
return 0;
}

