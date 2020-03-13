#include<stdio.h>

int max(int a, int b){
	return a>b?a:b;
}
int main(){
	int k,c;
	scanf("%d %d",&k,&c);
	
	for(int i=0;i<c;i++){
		int a, b;
		scanf("%d %d",&a,&b);
		
		int restRound=k-max(a,b);
		if((a >= b && a - restRound- b > 2) || (a < b && b - restRound- a > 1)){
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
}
