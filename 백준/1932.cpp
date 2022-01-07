#include<iostream>
#include<algorithm>
using namespace std;

int dp[501][501];

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            int tmp;
            cin>>tmp;
            if(i == j)
                dp[i][j] = dp[i-1][j-1] +tmp;
            
            else if(j == 1)
                dp[i][j] = dp[i-1][j] + tmp;
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+tmp;
        }
    }
    int result=0;
    for(int i=1;i<=N;i++){
        result=max(result,dp[N][i]);
    }
    cout<<result;
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
     */
}
