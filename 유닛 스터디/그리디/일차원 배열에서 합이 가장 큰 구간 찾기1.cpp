#include<stdio.h>
long long in[100001];

int main(){
	int n;
	scanf("%d ",&n);
	
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		in[i]=in[i-1]+tmp;
	}
	
	long long max=in[1],min=0,maxi=1,mini=1;
	
	for(int i=1;i<=n;i++){
		if(in[i]>max){
			maxi=i;
			max=in[i];
		}	 
		
		if(in[i]<min){
			mini=i+1;
			min=in[i];
		}
	}

	if(maxi>mini)
	printf("%d %d %d",mini,maxi,max-min);
	else{
		int min2=max,mini2;
		for(int i=1;i<maxi;i++){
			if(in[i]<min2){
				mini2=i;
				min2=in[i];
			}
		}
		
		int max2=min,maxi2;
		for(int i=mini+1;i<=n;i++){
			if(in[i]>max2){
				maxi2=i;
				max2=in[i];
			}
		}
		
		if(max-min2>max2-min){
			printf("%d %d %d",mini2,maxi,max-min2);
		}
		else
		printf("%d %d %d",mini,maxi2,max2-min);
		
		
	}
}
