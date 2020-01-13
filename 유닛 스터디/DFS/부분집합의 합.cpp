#include<stdio.h>
int n,s;
int in[1000000],cnt,chk[1000000];

void Sum(int sum, int a)
{
	
	if(a==n)
	{
		if(s==sum)
			cnt++;
		return;
	}
	Sum(sum,a+1);
	Sum(sum+in[a],a+1);

}

int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)	scanf("%d",&in[i]);
	Sum(0,0);
	if(s==0)	cnt--;
	printf("%d",cnt);
	
}
