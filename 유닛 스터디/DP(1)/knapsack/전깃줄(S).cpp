#include<iostream>
#include<algorithm>

using namespace std;
typedef struct a{
	int x, y;
}dot;

dot in[501]; 
int dp[5001];

int cmp(dot a, dot b )
{
	if(a.x<b.x){
		return 1;
	}
	return 0;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>in[i].x>>in[i].y;
	}	
	sort(in+1,in+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if((in[i].x-in[j].x)*(in[i].y-in[j].y)>=0){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);

	}
	printf("%d",n-ans);
}
