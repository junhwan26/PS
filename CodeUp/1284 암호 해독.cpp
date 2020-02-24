#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	int flag=1;

	
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			if(ans!=0){
				cout<<"wrong number";
				flag=0;
				break;
			}
			if(ans==0){
				n/=i;
				ans=i;
				i=1;	
			}
		}
	}
	if(flag){
		if(ans!=0)	
			printf("%d %d",ans,n);		
		else
			printf("wrong number");
	}
}
