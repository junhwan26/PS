#include<stdio.h>

int n,s;
int in[100000];
int main(){
	scanf("%d %d",&n,&s);
	int sum=0;
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		sum+=tmp;
		in[i]=sum;
	}
		
	int left=0,right=n;
	while(left!=right){
		
		int mid=(left+right)/2;
		int max=in[mid]-in[0];
		for(int i=0;i<n-mid;i++){
			int tmp=in[i+mid]-in[i];
			if(tmp>max){
				max=tmp;
			}
		}
	//	printf("%d %d %d\n",left,right,max);
		if(s<=max)
			right=mid;	
		else
			left=mid+1;
	}
	if(left==n&&in[n-1]-in[0]<s)
		printf("0");
	else
	printf("%d",left);

}
