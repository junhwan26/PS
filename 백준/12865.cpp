#include<iostream>

using namespace std;

int dp[101][100001];
int in[101][2]; //[0] : 무게, [1] : 가치

int main(){
    int N,K;
    cin>>N>>K;
    for(int i=1; i<=N;i++){
        cin>>in[i][0]>>in[i][1];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=in[i][0]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-in[i][0]]+in[i][1]);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[N][K];
}
