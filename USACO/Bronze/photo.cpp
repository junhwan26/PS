#include<iostream>
#include<stdio.h>
#include<iostream>
using namespace std;

int check[1001];

int main(){
	freopen("photo.in","r",stdin);
   	freopen("photo.out","w",stdout);
	
	int in[1001];
	int out[1001];
	
	int n;
	scanf("%d ",&n);
	
	for(int i=0;i<n-1;i++){
		scanf("%d",&in[i]);
	}
	
	int flag=1;
	for(int i=1;i<in[0];i++){
		flag=1;
		out[0]=i;
		
		for(int j=1;j<n;j++){
			int tmp=in[j-1]-out[j-1];
			
			if(tmp<=0||check[tmp]||tmp>n){
				flag=0;
				break;		
			}
			check[tmp]=1;
			out[j]=tmp;
			
		}
		
		for(int i=0;i<=n;i++)
			check[i]=0;
			
		if(flag==1)
			break;
	}
	
	
	for(int i=0;i<n;i++)
		if(i==n-1)
			printf("%d",out[i]);
		else 
			printf("%d ",out[i]);
}
