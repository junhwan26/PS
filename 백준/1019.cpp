#include<iostream>
using namespace std;
int ans[10];
int main(){
    int N;
    cin>>N;
    int tmp = 10;
    while(N>tmp/10){
        
        for(int i=1;i<=N%tmp;i++){
            ans[i]++;
        
        
        N%=tmp;
        tmp/=10;
        
    }
}
