#include<iostream>


long long dp[1000001];
int main (){
	long long n;
	std :: cin>>n;
	dp[0]=1;
	for(long long i=1;i<=n;i*=2)
	{
		for(long long j=1;j<=n;j++){
			if(j>=i)
				dp[j]+=dp[j-i]%1000000000;
		}
		//for(long long j=0;j<=n;j++)
		//	printf("%d ",dp[j]);
		//std :: cout<<"\n";
	}
	std :: cout<<dp[n]%1000000000;
}
