#include<stdio.h>
#include<vector>
using namespace std;

int n;
int len[1000000];

void moo(int k, int idx){
	//printf("%d %d\n",k,idx);
	if(!len[k])	
		len[k]=len[k-1]*2+k+3;
		
	if(k==0){
		if(idx==3||idx==2)
			printf("o");
		else if(idx==1)
			printf("m");
		return;
	}
	
	if(len[k-1]>=idx){
		moo(k-1,idx);
	}
	else if(len[k]>=idx){
		if(len[k-1]+k+3>=idx)
		{
			if(idx-len[k-1]==1){
				printf("m");
				return;
			}
			else{
				printf("o");
				return;
			}
			
		}
		else{
			moo(k-1,idx-len[k-1]-k-3);
		}
	}
	else{
		moo(k+1,idx);
	}
		

		
	
} 

int main(){
	scanf("%d",&n);
len[0]=3;

	
		moo(1,n);
	
}
