#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000001];
int main(){
	int n;
	cin>>n;
	dp[1]=0;
	for(int i=2;i<=n;i++)
		dp[i]=1000001;
		
	for(int i=2;i<=n;i++){
		int d1 = dp[i-1]+1;
		int d2 = dp[i];
		int d3 = dp[i];
				
		if(i%2==0)
			d2=dp[i/2]+1;
		
		if(i%3==0)
			d3=dp[i/3]+1;
			
		dp[i]=min(d1,min(d2,min(d3,dp[i])));
		
		//for(int j=1;j<=n;j++)
		//	printf("%d ",dp[j]);
		//cout<<"\n";
	}
	cout<<dp[n];
}
