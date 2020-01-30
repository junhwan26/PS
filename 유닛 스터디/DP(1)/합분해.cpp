#include<iostream>
#include<algorithm>


using namespace std;


long long dp[201][201];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
		dp[1][i]=1;
	for(int i=0;i<=k;i++)
		dp[i][0]=1;
	for(long long j=2;j<=k;j++){
		for(long long i=1;i<=n;i++){
			dp[j][i]+=(dp[j-1][i]+dp[j][i-1])%1000000000;
		}

			
	}	
	
	cout<<dp[k][n];
}
