#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n-1;++i)
    {
        char c1=s[i];
        char c2=s[i+1];
        if(c1>='A'&&c1<='Z') c1+=('a'-'A');
        if(c2>='A'&&c2<='Z') c2+=('a'-'A');
        if(c1>='a'&&c1<='z' && c2>='a'&&c2<='z')
        {
            if(c1==c2){
                cout<<c1<<c2<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}