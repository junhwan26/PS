#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
int dp[110000];
int coin[10000];



int main(){
 	int n,m;
 	cin>>m>>n;
 	int ans=0;
 	
	for(int i=0;i<n;i++){
 		cin>>coin[i];
	}
	for(int i=1;i<=m;i++)
		dp[i]=9999999;
	dp[0]=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			if(j>=coin[i])
				dp[j]=min(dp[j-coin[i]]+1,dp[j]);
		}
	//	for(int j=0; j<=m; j++) printf("%d ", dp[j]);
	//	printf("\n=%d\n", i);
 	}
	
	if(dp[m]==9999999)
		cout<<"-1";
	else
		cout<<dp[m];
	
	
 
}
