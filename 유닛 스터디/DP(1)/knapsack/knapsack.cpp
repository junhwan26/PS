#include<iostream>
#include<algorithm>
using namespace std;

int w[100],c[100];
int dp[100000];


int main(){
	
	int W,n;
	cin>>W>>n;
	for(int i=0;i<n;i++){
		cin>>w[i]>>c[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=W;j>=0;j--){
			if(j>=w[i])
			dp[j]=max(dp[j-w[i]]+c[i],dp[j]);
		}
	}
	
	cout<<dp[W];

}
