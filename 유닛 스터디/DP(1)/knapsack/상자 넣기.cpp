#include<iostream>
using namespace std;
int in[1001];
int dp[1001];

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>in[i];		
	}
	int ans=0;
	
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<=i;j++){
			if(in[i]>in[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	
	cout<<ans;
}
