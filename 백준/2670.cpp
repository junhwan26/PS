#include<iostream>
#include<algorithm>
#include<stdio.h>
double dp[10001];

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>dp[i];
    }
    
    double ans=dp[1];
    
    for(int i=1;i<=N;i++){
        dp[i] = max(dp[i], dp[i]*dp[i-1]);
        
        ans = max(dp[i],ans);
    }
    
    printf("%.3lf",ans);
}
