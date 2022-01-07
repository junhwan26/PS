#include<iostream>
using namespace std;

int dp[501][501];
int in[501];


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>in[i];
            in[i]+=in[i-1];

        }
        
        for(int i =1; i<=N; i++){
            for(int start = 1; start + i <= N; start++){
                dp[start][start+i] = 987654321;
                for(int k=start; k < start+i;k++){
                    dp[start][start+i] = min(dp[start][k] + dp[k+1][start+i] + in[start+i] - in[start-1], dp[start][start+i]);
                }
            }
        }
        
        /*
        for(int i =1;i<=N;i++){
            for(int j=1;j<=N;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        cout<<dp[1][N]<<"\n";
        
        
    }
    
}
