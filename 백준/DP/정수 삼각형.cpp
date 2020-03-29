#include<iostream>
using namespace std;

int in[501][501];
int dp[501][501];
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>in[i][j];
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+in[i][j];
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;
}
