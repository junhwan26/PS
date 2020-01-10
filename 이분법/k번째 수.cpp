#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,k;
	cin>>n;
	cin>>k;
	int left=1,right=k,mid;
	
	while(left!=right){
		//printf("%d %d\n",left, right);
		int cnt=0;
		mid=(right+left+1)/2;
		for(int i=1;i<=n;i++)
			cnt+=min((mid-1)/i,n);
		//printf("%d %d %d %d\n",left, right,mid,cnt);
		
		if(cnt>=k){
			right=mid-1;
		}
		
		else{
			left=mid;
		}
	}
	
	printf("%d",left);
	
}

