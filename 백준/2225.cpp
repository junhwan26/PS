#include<iostream>
using namespace std;

long long  dp[201][201];
long long func(int n, int k){
    if(dp[n][k])
        return dp[n][k];
    
    if(k==1)
        return dp[n][k] = 1;
    
    long long result = 0;
    for(int i=0;i<=n;i++){
        result += func(n-i,k-1);
        result %= 1000000000;
    }
    return dp[n][k] = result%1000000000;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<func(n,k);
}
