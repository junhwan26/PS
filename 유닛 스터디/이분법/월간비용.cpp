#include<iostream>
using namespace std;
int in[100000];
int n,m;

int count(int a){
	int now=a;
	int cnt=1;
	for(int i=0;i<n;i++){
		if(in[i]>a)
			return 10000000;
		if(in[i]<=now){
			now-=in[i];
		}
		else{
			now=a-in[i];
			cnt++;
		}
	}	
	return cnt;
}

int main(){
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	int left=0;
	int right=100000;
	int mid;
	while(left!=right){
		mid=(left+right)/2;
		int cnt=count(mid);
		//printf("%d %d %d %d\n",left, right,mid,cnt);
		if(cnt<=m){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
		printf("%d",left);
}
