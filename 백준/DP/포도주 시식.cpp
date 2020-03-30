#include<iostream>
using namespace std;
int in[10001];
int dp[10001][2];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
		
	dp[1][1]=in[1];
	for(int i=2;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=max(dp[i-2][0]+in[i-1],dp[i-1][0])+in[i];
	}
	cout<<max(dp[n][0],dp[n][1]);
}
