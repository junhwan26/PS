#include<iostream>

using namespace std;
int dp[1000001];

int main(){
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=1000000;i++){
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }
    int N;
    cin>>N;
    cout<<dp[N];
}
