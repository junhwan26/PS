#include<stdio.h>

int main()
{
	int h,n,maxh;
	maxh=h;
	scanf("%d %d",&h,&n);
	for(int i=0;i<n;i++)
	{
		int a;
		int tmp;
		scanf("%d %d",&a,&tmp);
		if( a==1)
		{
			h-=tmp;
		}
		else if(a==2)
		{
			h+=tmp;	
		}
		else if(a==3)
		{
			h+=tmp;
			maxh=h;
		}
		
	}
	printf("%d",maxh);
}
