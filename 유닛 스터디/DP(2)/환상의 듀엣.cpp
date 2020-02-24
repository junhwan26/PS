#include<iostream>
#include<algorithm>
#define MAX 2000000000
using namespace std;
int in[2001];
int sum[2001];
int dp[2001][2001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>in[i];
		sum[i]=sum[0]+in[i];
	}
	int ans=MAX;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i>j){
				
				dp[i][i+1]=min(dp[i][i+1],dp[i][j]+abs(in[i+1]-in[j]))
				dp[i+1][j]=min(dp[i+1][j]),dp[i][j]+abs(in[i+1]-in[i])	
			}
			else if(i<j){
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]+abs(in[j+1]-in[j]))
				dp[j+1][j]=min(dp[j+1][j]),dp[i][j]+abs(in[j+1]-in[i])	
				
			}
		}
	}
	
	for(int i=1;i<)
		
	cout<<ans;

}
