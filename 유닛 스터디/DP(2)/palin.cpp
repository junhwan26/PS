#include<iostream>
#include<string>
using namespace std;

int dp[5002][5002];
char a[5002],b[5002];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[n-i+1]=a[i];
	}
	
	int ans=0;
	int m=n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
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
	
	cout<<n-ans;
}
