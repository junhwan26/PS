#include<stdio.h>
int main()
{
	int in[2][110];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[0][i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[1][i]);
	}
	int min=100;
	for(int i=0;i<n;i++)
	{
		if(in[1][i]==0) continue;
		if(in[0][i]/in[1][i]<min)
			min=in[0][i]/in[1][i];
	}
	printf("%d",min);
}
