#include<iostream>
using namespace std;
int dpmin[1001];
int dpmax[1001];
int in[1001];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	int ans=0;
	
	for(int i=1;i<=n;i++)
	{
		dpmax[i]=1;
		for(int j=1;j<=i;j++){
			if(in[j]<in[i])
				dpmax[i]=max(dpmax[i],dpmax[j]+1);
		}	
	}
	
	for(int i=n;i>=1;i--){
		dpmin[i]=1;
		for(int j=n;j>=i;j--)
			if(in[j]<in[i])
				dpmin[i]=max(dpmin[i],dpmin[j]+1);
	}
	
	for(int i=1;i<n;i++){
		ans=max(dpmin[i]+dpmax[i],ans);
	}
	
	cout<<ans-1;
	
}
