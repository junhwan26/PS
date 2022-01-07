#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
    string str;
    cin>>str;
    regex re("(100+1+|01)+");
    if(regex_match(str,re))
        cout<<"YES\n";
    else
        cout<<"NO\n";}
}

