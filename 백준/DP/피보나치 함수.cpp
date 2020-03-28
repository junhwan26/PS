#include<iostream>
using namespace std;
int cnt1, cnt0;
int dp[50][2];

int main(){
	dp[0][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=50;i++){
		dp[i][0]=dp[i-1][0]+dp[i-2][0];
		dp[i][1]=dp[i-1][1]+dp[i-2][1];
	}
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		cout<<dp[tmp][0]<<" "<<dp[tmp][1]<<"\n";
	}
}
