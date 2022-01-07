#include<iostream>

using namespace std;

int dp[1025][1025];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 이거 안쓰면 시간초과
    
    
    int N,M;
    cin>>N>>M;
    int tmp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            
            cin>>tmp;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + tmp;
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    int x1,y1,x2,y2;
    for(int i=0;i<M;i++){
        cin>>x1>>y1>>x2>>y2;
        cout<< dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]<<"\n";
    }
    
}
