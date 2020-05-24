#include<iostream>
#include<algorithm>
using namespace std;
typedef struct dot{
	int x,y;
}dot;

dot in[101];
int dp[101];

int cmp(dot a, dot b){
	return a.x<b.x;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i].x>>in[i].y;
	
	sort(in+1,in+n+1,cmp);

	int ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<i;j++){
			if(in[i].y>in[j].y){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<n-ans;
}
