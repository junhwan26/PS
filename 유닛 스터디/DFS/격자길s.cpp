#include<stdio.h>

int n,m;
int cnt;

void check(int a, int b)
{
	if(b>(m*a/n)||a>n||b>m)
		return;
	if(a==n&&b	==m)
	{
		cnt++;
		return;
	}
	check(a+1,b);
	check(a,b+1);
	
}
int main()
{
	scanf("%d %d",&n,&m);
	check(0,0);
	printf("%d",cnt);
}
