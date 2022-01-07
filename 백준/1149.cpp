#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000][3];
int RGB[1000][3];
int main(){
    int N;
    cin>>N;
    
    for(int i=0 ; i<N ; i++)
        cin>>RGB[i][0]>>RGB[i][1]>>RGB[i][2];
    
    dp[0][0] = RGB[0][0];
    dp[0][1] = RGB[0][1];
    dp[0][2] = RGB[0][2];
    
    for(int i=1 ; i<N ; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + RGB[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + RGB[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + RGB[i][2];
    }
    cout<<min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
}
