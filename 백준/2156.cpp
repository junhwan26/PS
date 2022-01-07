#include<iostream>

using namespace std;

int in[10001];
int dp[10001][3];

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>in[i];
    }
    
    dp[1][1] = in[1];
    
    for(int i=2; i<=N;i++){
        dp[i][0] = max(dp[i-1][2], max(dp[i-1][0],dp[i-1][1]));
        dp[i][1] = dp[i-1][0] + in[i];
        dp[i][2] = dp[i-1][1] + in[i];
    }


    cout<<max(dp[N][0], max(dp[N][1], dp[N][2]));
}
