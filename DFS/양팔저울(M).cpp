#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
int choo[14];
int check[3000000];

int n,s;
void dfs(int sum,int k){
	if(sum>0)
		check[sum]=1;
	//printf("%d %d\n",k,sum);
	if(k==n+1){
		if(sum>0)
			check[sum]=1;
		return;
	}
	dfs(sum+choo[k],k+1);
	dfs(sum,k+1);
	dfs(sum-choo[k],k+1);
}
int main(){

	scanf("%d",&n);
	for(int i=n-1;i>=0;i--){
		scanf("%d",&choo[i]);
		s+=choo[i];
	}
	dfs(0,0);
	int ans=0;
	for(int i=1;i<=s;i++){
		if(!check[i])
			ans++;
	}
	printf("%d",ans);
		
}
