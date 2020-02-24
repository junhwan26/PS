#include<iostream>

using namespace std;

int dp[42];

int f(int n){
	
	if(dp[n])	
		return dp[n];

	dp[n]=f(n-1)+f(n-2);
	return dp[n];

}

int main(){
	int n;
	dp[1]=1;
	dp[2]=1;
	
	cin>>n;
	cout<<f(n);
}
