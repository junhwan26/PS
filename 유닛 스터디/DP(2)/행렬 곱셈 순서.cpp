#include<iostream>
int in[501][2];
int dp[501][501];
#define MAX 2147483647
using namespace std;

int main(){

	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>in[i][0]>>in[i][1];
	
	
	for(int i=1;i<n;i++){
		dp[i][i+1]=in[i][0]*in[i][1]*in[i+1][1];
	}
	
	/*
		
	*/
		for(int j=2;j<=n;j++)
		{
			for(int i=1;i<=n-j;i++){
				dp[i][i+j]=MAX;
				for(int k=i;k<=i+j;k++){
					dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+in[i][0]*in[k][1]*in[i+j][1]);
				}
			}
		}
		
		
	
	cout<<dp[1][n];
		
}
