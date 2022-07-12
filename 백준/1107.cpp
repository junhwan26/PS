#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int broken[10];
using namespace std;
string N;
vector<int> v;
int NUM;
int ans=99999999;
int calc(int num){
    return abs(num-NUM) + to_string(num).length();
}
void f(int a, int num){
    if(a>7)
        return;

    if(ans>calc(num)){
        ans = calc(num);
        //cout<<num<<endl;
    }
    for(int i=0; i<v.size();i++){
        f(a+1,num*10 + v[i]);
    }
    
}

int main(){
    
    cin>>N;
    int m;
    cin>>m;
    for(int i=0; i<N.size();i++){
        NUM*=10;
        NUM+=N[i]-'0';
    }
    
    while(m--){
        int tmp;
        cin>>tmp;
        broken[tmp] = 1;
    }
    
    for(int i=0; i<10; i++){
        if(!broken[i])
            v.push_back(i);
    }
    for(int i=0; i<v.size();i++){
        f(1,v[i]);
    }
    cout<<min(ans, abs(100-NUM));
}
