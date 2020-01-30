#include<algorithm>
#include<iostream>
using namespace std;

int dp[100001];
int coin[100];

int main(){
	int n,k;
	cin>>n>>k;
	//cout<<n<<" "<<k;
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}	
	
	dp[0]=0;
	for(int i=1;i<=k;i++)
		dp[i]=100001;

	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			if(j>=coin[i])
				dp[j]=min(dp[j-coin[i]]+1,dp[j]);
		}
		
	//	for(int j=0; j<=k; j++) printf("%d ", dp[j]);
	//	printf("\n=%d\n", i);
	}
	
	if(dp[k]==100001)
		cout<<"-1";
	else
		cout<<dp[k];
}
