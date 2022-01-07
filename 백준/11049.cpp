#include<iostream>
using namespace std;

int dp[501][501];
int in[501][2];

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>in[i][0]>>in[i][1];
    
    for(int i=1;i<=N;i++){
        for(int start = 1; start+i<=N; start++){
            dp[start][start+i] = 2147483647;
            for(int k = start; k < start+i; k++){
                dp[start][start+i] = min( dp[start][start+i], dp[start][k] + dp[k+1][start+i] + in[start][0] * in[k][1] * in[start+i][1]);
            }
        }
    }
    cout<<dp[1][N];
}
