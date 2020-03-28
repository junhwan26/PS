#include<iostream>
using namespace std;

long long dp[101]={0,1,1,1,2,2,};
int main(){
	int n;
	cin>>n;
	for(int i=6;i<=100;i++){
		dp[i]=(dp[i-1]+dp[i-5]);
	}
	
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		cout<<dp[tmp]<<"\n";
	}
}
