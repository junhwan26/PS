#include<stdio.h>

long long n,m;

int main()
{
	scanf("%lld %lld",&n,&m);
	long long cnt=0,j;
	/*for(long long i=n;i<=m;i++)
	{
		for(  j=1;j*j<i;j++)
		{
			if(i%j==0)
				sum+=2;	
		}
		if(j*j==i)
			sum++;
	}
*/	int i;
	for( i=1;i<=m;i++)
	{
		for(j = 1; j<=m/i;j++)
		{
			if(i*j>=n&&i*j<=m)
				cnt++;
		}
	}
	printf("%lld",cnt);
}
