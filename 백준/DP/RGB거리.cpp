#include<iostream>
using namespace std;

int cost[1000][3];
int dp[1000][3];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
	}
	
	dp[0][0]=cost[0][0];
	dp[0][1]=cost[0][1];
	dp[0][2]=cost[0][2];
	
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			dp[i][j]=min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+cost[i][j];
		}
	}	
	
	cout<<min(min(dp[n-1][1],dp[n-1][0]),dp[n-1][2]);
}
