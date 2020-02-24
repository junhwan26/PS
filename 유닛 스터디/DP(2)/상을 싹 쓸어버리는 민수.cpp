#include<iostream>
using namespace std;
int in[502][502];
int check[502][502];
int dp[502][592];
int dir[2][4]={{1,-1,0,0},{0,0,-1,1}};
int f(int a,int b){
	if(dp[a][b])
		return dp[a][b];
	int flag=1;
	for(int i=0;i<4;i++){
		int na=a+dir[0][i],nb=b+dir[1][i];
		if(!in[na][nb]||check[na][nb]||in[na][nb]<in[a][b])
			continue;
		flag=0;
		check[na][nb]=1;
		dp[a][b]=max(f(na,nb)+1,dp[a][b]);
		check[na][nb]=0;
	}
	if(flag)
		return 1;
	
	return dp[a][b];
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>in[i][j];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,f(i,j));
		}
	}
	cout<<ans;
}
