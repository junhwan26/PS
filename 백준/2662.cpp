#include<iostream>

using namespace std;

int dp[301][21];
int in[301][21];
int check[301][21];
int ans[21];
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int money;
        cin>>money;
        for(int j=1;j<=M;j++){
            int re;
            cin>>re;
            in[money][j] = re;
        }
    }
    for(int i=1;i<=M;i++){
        for(int cost = 1; cost <= N; cost++){
            for(int j=0;j<=cost;j++){
                if(dp[cost][i] < dp[cost-j][i-1] + in[j][i]){
                    dp[cost][i] =  dp[cost-j][i-1] + in[j][i];
                    check[cost][i] = j;
                }
            }
        }
    }
    cout<<dp[N][M]<<endl;
    
    for(int i=1; i<=N; i++){
        for(int j=1;j<=M;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    for(int i=1; i<=N; i++){
        for(int j=1;j<=M;j++)
            cout<<check[i][j]<<" ";
        cout<<endl;
    }

    
    int cost = N;
    
    for(int i=M;i>0; i--){
        //cout<<i<<" "<<check[cost][i]<<"\n";
        ans[i] = check[cost][i];
        cost-= check[cost][i];
    }
    for(int i=1;i<=M;i++)
        cout<<ans[i]<<" ";
}

/*
 4 3
 1 5 1 3
 2 6 5 6
 3 7 100 20
 4 10 13 40
 */
