#include<iostream>
using namespace std;

int dp[1000];
int in[1000];
int main(){
    int N,ans = 1;
    cin>>N;
    
    for(int i=0; i < N ; i++)
        cin>>in[i];
    
    for(int i=0; i<N ; i++){
        dp[i] = in[i];
        for(int j=i-1; j>=0 ; j--){
            if(in[j]<in[i])
                dp[i] = max(dp[j]+in[i], dp[i]);
            
        }
        ans = max(dp[i],ans);
        //cout<<dp[i]<<" ";
    }
    
    cout<<ans;
}

