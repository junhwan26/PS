#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> v;

int main(){
    
    for(int i=0; i<5; i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(v[j].length()>i)
                cout<<v[j][i];
        }
    }
}

