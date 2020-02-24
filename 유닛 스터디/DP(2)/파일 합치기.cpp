#include<iostream>
using namespace std;
int dp[510][510];
int in[510];
int main(){
	int T;
	cin>>T;
	
	for(int o=0;o<T;o++){
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			int tmp;
			cin>>tmp;
			in[i]=in[i-1]+tmp;
		}
			
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n-j;i++){
				dp[i][i+j]=250*5010000;
				for(int k=i;k<=i+j;k++)
				{
					dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+in[i+j]-in[i-1]);
				}

			}
		}
		
		cout<<dp[1][n]<<"\n";
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				dp[i][j]=0;
		}
	}
}
