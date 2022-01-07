#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<char> v;

int L,C;
void func(string r, int c){
    if(r.length() == L){
        int check1=0, check2=0;
        for(int i=0;i<L;i++){
            if(r[i] == 'a' || r[i] == 'e' || r[i] == 'i' || r[i] == 'o' || r[i] == 'u')
                check1 = 1;
            else
                check2++;
        }
        if(check1 && check2 >= 2)
            cout<<r<<"\n";
    }
    
    for(int i=c+1;i<=C;i++)
        func(r+v[i],i);
    
    
}

int main(){
    cin>>L>>C;
    v.push_back('a');
    for(int i=1;i<=C;i++){
        char tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=1;i<=C;i++){
        string tmp = "";
        tmp+=v[i];
        func(tmp,i);
    }
}
