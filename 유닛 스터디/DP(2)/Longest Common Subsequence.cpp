#include<iostream>
#include<string>
using namespace std;

int dp[4002][4002];

int main(){
	string a,b;
	cin>>a;
	cin>>b;
	int ans=0;
	int n=a.length();
	int m=b.length();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]+=1;
				dp[i+1][j+1]=dp[i][j];
			}
			else{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);				
			}
		}
		/*
		for(int j=1;j<=n+1;j++){
			for(int k=1;k<=m+1;k++)
				cout<<dp[j][k]<<" ";
			cout<<"\n";
		}
		cout<<"\n";*/
	}
	
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i][m+1]);
	}
	
	for(int j=1;j<=m+1;j++){
		ans=max(ans,dp[n+1][j]);
	}
	
	cout<<ans;
}
