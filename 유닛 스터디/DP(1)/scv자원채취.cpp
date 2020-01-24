#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
	int n;
int cnt[101][101];
int in[101][101];

int main(){

	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>in[i][j];
			cnt[i][j]=max(cnt[i-1][j],cnt[i][j-1])+in[i][j];
		}
			
	}

	
	cout<<cnt[n][n];
}
