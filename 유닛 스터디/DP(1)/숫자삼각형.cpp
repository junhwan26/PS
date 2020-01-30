#include<iostream>
#include<algorithm>
using namespace std;

int in[502][502];
int dp[502][502]; 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>in[i][j];
		}
	}
	
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i+1][j]+in[i][j],dp[i+1][j+1]+in[i][j]);
		}
		

	}
	cout<<dp[1][1];
}
