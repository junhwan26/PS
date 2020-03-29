#include<iostream>
using namespace std;
int dp[101][10];
int main(){
	int n;
	cin>>n;
	//초기항 설정 
	for(int i=1;i<=9;i++){
		dp[1][i]=1;
	}
	
	//찾기 
	for(int i=2;i<=n;i++){
		dp[i][0]=dp[i-1][1]%1000000000;
		dp[i][9]=dp[i-1][8]%1000000000;
		for(int j=1;j<=8;j++){
			dp[i][j]=(dp[i-1][j-1]%1000000000+dp[i-1][j+1]%1000000000)%1000000000;	
		}
	}
	int ans=0;
	for(int i=0;i<=9;i++){
		ans+=dp[n][i];
		ans%=1000000000;
		
	}
	cout<<ans%1000000000;
}
