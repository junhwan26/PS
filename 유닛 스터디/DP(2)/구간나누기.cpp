#include<iostream>
#define MAX 3276801
using namespace std;
int in[101];
int dp[101][52][2]; 
int main(){
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>in[i];
	}

	
	dp[0][0][0]=0;
	dp[0][0][1]=-MAX;
	for(int i=1;i<=n;i++){
		dp[0][i][1]=-MAX;
		dp[0][i][0]=-MAX;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0])+in[i];
			dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0]);
		}
	}
		
	cout<<max(dp[n][m][1],dp[n][m][0]);
}

