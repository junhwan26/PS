#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

int in[1000];
int use[1000];
void copy(){
	for(int i=0;i<1000;i++)
		use[i]=in[i];
}

void print(int a){
	for(int i=0;i<a;i++)
		printf("%d ",in[i]);
}

int main(){
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);	
	int N,K;
	scanf("%d %d",&N,&K);
	//fflush(stdin); 
	for(int i=0;i<N;i++){
		scanf(" %d" ,&in[i]);
	}

	sort(in,in+N,greater<int>());
	//print(N);
	//printf("\n");
	int max=0;
	int O=in[0];
	
	for(int num=0;num<O;num++){
		copy();
		int sum=0;
		int cnt=0;
		int j=0;
		//printf("%d\n",num);
		while(cnt<K/2&&j<N){
			if(use[j]>num){
				//printf("%d %d\n",num,use[j]);
				use[j]-=num;
				cnt++;
				if(cnt>=K) break;
			}else{
				j++;
			}
		}
		
		if(cnt!=K/2)
			break;
		
		sort(use,use+N,greater<int>());
		
		cnt=0;
		int ck=0;
		j=0;
		while(cnt<K/2&&j<N){
			if(use[j]>num){
				//printf("%d %d\n",num,use[j]);
				use[j]-=num;
				cnt++;
				sum+=num;
				if(cnt>=K) break;
			}else{
				j++;
			}
		}
		sort(use,use+N,greater<int>());
		j=0;
		while(cnt<K/2&&j<N){
			cnt++;
			sum+=use[j];
			j++;
		}
		
		if(sum>max)
			max=sum;
	}
	printf("%d",max);
}
