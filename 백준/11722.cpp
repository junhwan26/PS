#include<iostream>
#include<algorithm>
int dp[1000];
int in[1000];
using namespace std;

int main(){
    int N,ans=0;
    cin>>N;
    
    for(int i=0; i < N; i++)
        cin >> in[i];
    
    for(int i = N-1 ; i>=0; i--){
        dp[i] = 1;
        for(int j=i+1; j<N; j++){
            if(in[i]>in[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    
    cout<<ans;
}
