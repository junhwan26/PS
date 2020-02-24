#include<iostream>
using namespace std;
int dp[101][101][101];

int main(){
	long long n,r,l;
	cin>>n>>r>>l;
	for(long long i=1;i<=n;i++){
		dp[i][i][1]=1;
		dp[i][1][i]=1;	
	}
	
	
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=l;j++){
			for(long long k=1;k<=r;k++){
				dp[i][j][k]=(dp[i-1][j-1][k]+dp[i-1][j][k-1]+(i-2)*dp[i-1][j][k]%1000000007)%1000000007;
			}			
		}
	}
	cout<<dp[n][l][r]%1000000007;
}
