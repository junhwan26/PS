#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main(){
    string str;
    cin>>str;
    regex re("(100+1+|01)+");
    if(regex_match(str,re))
        cout<<"SUBMARINE";
    else
        cout<<"NOISE";
}
