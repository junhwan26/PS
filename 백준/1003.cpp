#include <iostream>
#include<string>
using namespace std;
int cnt[26];
int dp[41][2];

string str;
int cnt0,cnt1;


int main(int argc, const char * argv[]) {
    dp[0][0]=1;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    
    for(int i=2;i<=40;i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][0];
        dp[i][1]=dp[i-1][1]+dp[i-2][1];
    }
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        cout<<dp[n][0]<<" "<<dp[n][1]<<"\n";
    }
    
}
