#include<stdio.h>
int a[1000][1000];
int cnt[1000];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)cnt[i]++;
		}
	}
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(cnt[i]%2==1)
		flag++;
	}
	
	if(flag==2||flag==0)
	printf("YES");
	else
	printf("NO");
}
