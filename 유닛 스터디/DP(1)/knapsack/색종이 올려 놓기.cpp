#include<iostream>
#include<algorithm>
using namespace std;

typedef struct dot{
	int x, y;
}dot;

dot p[1001];
int dp[1001];
int cmp(dot a, dot b){
	if(a.x<b.x){
		return 0;
	}
	else if(a.x==b.x&&a.y<b.y){
		return 0;
	}
	return 1;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int tempx, tempy;
		cin>>tempx>>tempy;
		if(tempx>=tempy){
			p[i].x=tempx;
			p[i].y=tempy;
		}
		else{
			p[i].y=tempx;
			p[i].x=tempy;
		}
	}
	sort(p,p+n,cmp);
	
	//for(int i=0;i<n;i++)
	//	cout<<p[i].x<<" "<<p[i].y<<"\n";
	int ans=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(p[i].x<=p[j].x&&p[i].y<=p[j].y)
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}
