#include<stdio.h>
int in[10000][10000];
void f(int a, int b, int n){

	if(n==3){	//printf("%d %d %d\n",a,b,n);
		for(int j=a;j<a+3;j++){
			for(int i=b;i<b+3;i++){
				if(j==a||i==b||j-2==a||i-2==b){
					//printf("filled %d %d\n",j,i);
					in[j][i]=1;
				}
					
				//else
					//printf("*\n");
			}
		}
		return;
	}
	
	f(a,b,n/3);
	f(a,b+n/3,n/3);
	f(a,b+2*n/3,n/3);

	f(a+n/3,b,n/3);
	
	f(a+n/3,b+2*n/3,n/3);

	f(a+2*n/3,b,n/3);
	f(a+2*n/3,b+n/3,n/3);
	f(a+2*n/3,b+2*n/3,n/3);



}


int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("*");
		return 0;
	}

	f(1,1,n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			if(in[i][j]==1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}
