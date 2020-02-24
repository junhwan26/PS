#include<iostream>

int dp[1001][1001];
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int tmp;
			cin>>tmp;
			dp[i][j]=max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+tmp;
		}
			
	}
	cout<<dp[n][m];
}
