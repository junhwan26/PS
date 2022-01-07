#include<iostream>
using namespace std;
int N[1000001];

int main(){
    int n;
    cin>>n;
    N[1]=0;
    N[2]=1;
    N[3]=1;
    for(int i=4;i<=n;i++){
        N[i] = N[i-1]+1;
        if(i%2==0)
            N[i] = min(N[i],N[i/2]+1);
        if(i%3==0)
            N[i] = min(N[i],N[i/3]+1);
    }
    cout<<N[n];
}
