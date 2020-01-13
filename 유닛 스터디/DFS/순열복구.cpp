#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char in[51];
int check[31],ans[31], N, flag;
void sep(int n, int a)
{
	//printf("a=%d ",a);
	if(flag==1) return;
	if(n<0||a==N)
	{
		flag=1;
		return;
	}
	int num=10*(in[n-1]-'0')+in[n]-'0';
	if(n>=1&&num>0&&num<=N&&!check[num]&&in[n-1]!='0')
	{
		ans[a]=num;
		check[num]=1;
		sep(n-2,a+1);
		if(flag==1)	return;
		check[num]=0;
	}
	num=in[n]-'0';
	if(num<=N&&!check[num])
	{
		ans[a]=num;
		check[num]=1;
		sep(n-1,a+1);
		if(flag==1)	return;
		check[num]=0;
	}

}

int maxnum(int n)
{
	if(n<=9)
		return n;
	else
	{
		return 9+(n-9)/2;
	}
}

int main()
{
	scanf("%s",in);
	N=maxnum(strlen(in));
	//printf("%d\n",N);
	sep(strlen(in)-1,0);
	for(int i=N-1;i>=0;i--)
	{
		printf("%d ",ans[i]);
	}
}
