#include<stdio.h>
int n;
int in[508][508];
int ans1;
int ans2;

void two(int a, int b){
	for(int i=b;i<b+2;i++){
		for(int j=a;j<a+2;j++){
			if(in[j][i]==1)
				ans1++;
			else
				ans2++;
		}
	}		
}


void devide(int ax, int bx, int ay, int by){
	
	int check=0;
	
	int first=in[ax][ay];
/*
	for(int i=ay;i<=by;i++)
	{
		for(int j=ax;j<=bx;j++)
			printf("%d ",in[j][i]);
		printf("\n");
	}
*/	

	
	for(int i=ay;i<=by;i++){
		
		for(int j=ax;j<=bx;j++){
		
			if(first!=in[j][i]){
				check=1;
				break;
			}
		
		}
		if(check==1)
			break;
	}
	
	if(!check){
		if(first==1)
			ans1+=1;
		else
			ans2+=1;
			//printf("1: %d, 0: %d\n\n",ans1,ans2);
	}
	else if(bx-ax==1) {
		two(ax,ay);	
		//printf("1: %d, 0: %d\n\n",ans1,ans2);
	
	
	}else
	{
		
		devide(ax,(ax+bx)/2,ay,(ay+by)/2);
		devide(ax,(ax+bx)/2,(ay+by)/2+1,by);
		
		devide((ax+bx)/2+1,bx,(ay+by)/2+1,by);
		devide((ax+bx)/2+1,bx,ay,(ay+by)/2);
		
	}
		
}

int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			scanf("%d",&in[j][i]);
		}
	}
		
	devide(1,n,1,n);
	printf("%d\n%d",ans2,ans1);
}
