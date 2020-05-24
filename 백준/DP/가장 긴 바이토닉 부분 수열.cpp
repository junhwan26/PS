#include<iostream>
using namespace std;
int in[1002];
int dp[1002][2];

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>in[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(in[i]>in[j])
				dp[i][0]=max(dp[i][0],dp[j][0]+1);
		}
	}
	
	for(int i=n;i>=1;i--){
		for(int j=n+1;j>i;j--){
			if(in[i]>in[j])
				dp[i][1]=max(dp[i][1],dp[j][1]+1);
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		ans=max(ans,dp[i][0]+dp[i][1]);
	}

	cout<<ans-1;
	
}
