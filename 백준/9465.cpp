#include<iostream>
using namespace std;
int dp[100000][2];
int in[100000][2];
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>in[i][0];
        }
        for(int i=1;i<=N;i++){
            cin>>in[i][1];
        }
        dp[1][0] = in[1][0];
        dp[1][1] = in[1][1];
        for(int i=2;i<=N;i++){
            dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + in[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + in[i][1];
            
        }
        
        //for(int i=0;i<=N;i++)
        //    cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        cout<<max(dp[N][0], dp[N][1])<<"\n";
        for(int i=1;i<=N;i++){
            dp[i][0]=0;
            dp[i][1]=0;
            in[i][0]=0;
            in[i][1]=0;
        }
    }
}
