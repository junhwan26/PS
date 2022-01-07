#include<iostream>
using namespace std;
long long dp[101][10][1<<10];

int main(){
    int N;
    cin>>N;
    
    for(int i=0;i<=9;i++){
        dp[1][i][1<<i]=1;
    }
    
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            int tmp = 1<<j;
            for(int k=1;k<=1023;k++){
                
                if(j==0)
                    dp[i][0][k|tmp] += (dp[i-1][1][k])%1000000000;
                else if(j==9)
                    dp[i][9][k|tmp] += (dp[i-1][8][k])%1000000000;
                else
                    dp[i][j][k|tmp] += (dp[i-1][j-1][k] + dp[i-1][j+1][k])%1000000000;
                //if(dp[i][j][k|tmp])
                //cout<<i<<" "<<j<<" "<<(k|tmp)<<" "<<dp[i][j][k|tmp]<<endl;
            }
        }
    }
    long long result=0;
    for(int i=1; i<=9; i++)
        result += dp[N][i][1023];
    cout<<result%1000000000;
}

