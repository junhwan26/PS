#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

long long int v[100001];
int n;


long long dis(long long a)
{
	long long int cnt = 0;
	
	for (long long int i = 0; i < n; i++)
	{
		cnt += abs(a*i-v[i]);
	}
	return cnt;
}


int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &v[i]);
		
	}

	//for (int i = 0; i < n; i++)
	//	printf("%d ",v[i]);
	int sum=0;
	
	//printf("%d",sum);
	
	long long int s=0;
	long long int e=1000000000;

	long long int left;
	long long int right;
			
	while(s+2!=e){
		left=(long long int)(s*2+e)/3;
		right=(long long int)(s+2*e)/3;
		//printf("%d %d %d %d\n",s,left,right,e);
		//printf("dif(left) %d  dis(right)%d\n",dis(left),dis(right));
		if(dis(left)>dis(right))
			s=left;
		else if(dis(left)<dis(right))
			e=right;
		else{
		}
	}
	min=dis(s);
	for(int i=s+1;i<=e;i++){
		if(dis(i)<min){
			min=dis(i);
		}
	}
	printf("%d",min);
}
