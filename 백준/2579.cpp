#include<iostream>
using namespace std;
long long dp[301][2];
long long in[301];
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>in[i];
    }
    dp[1][1] = in[1];
    dp[2][0] = in[2];
    dp[2][1] = in[2] + dp[1][1];
    //dp[3][2] = dp[2][1] + in[3];
    
    for(int i=3;i<=N;i++){
        dp[i][0] = max( dp[i-2][1], dp[i-2][0]) + in[i];
        dp[i][1] = dp[i-1][0] + in[i];
    }
    
    cout<<max(dp[N][1], dp[N][0]);
    /*
    for(int i=1;i<=N;i++){
        cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
     */
}
