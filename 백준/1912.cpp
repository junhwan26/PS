#include<iostream>

using namespace std;
int dp[100001];

int main(){
    int N,ans=-987654321, m = 0;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>dp[i];
        dp[i]+=dp[i-1];
        ans = max(ans,dp[i]-m);
        m = min(m,dp[i]);
    }
    cout<<ans;
    
}
