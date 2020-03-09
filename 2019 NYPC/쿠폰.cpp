#include<stdio.h>
int in[1000][2];

void next(int a)
{
	for(int i=0;i<n;i++)
	{
		in[i][0]-=a;
		if(in[i][0]<0)
		in[i][0]=0;
	}
}
int end{
	for(int i=0;i<n;i++)
	{
		if(in[i][0]!=0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&in[i][0],&in[i][1]);
	}	

	int ans;
	while(end())
	{
		int max	=0, maxi;
		for(int i=0;i<n;i++)
		{
			if(in[i][0]+in[i][1]>max)
			{
				max=in[i][0]+in[i][1];
				maxi=i;
			}
			else if(in[i][0]+in[i][1]==max)
			{
				if(in[i][0]>)
			}
		}
		ans+=in[maxi][1];
		next(in[maxi][1]);
	}
	printf("%d",ans);
}
