#include<stdio.h>
int umb[10];

int main()
{
	int n,m,bc;
	int cnt=0;
	scanf("%d %d %d",&n,&m,&bc);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(b==1)
			umb[a]++;
		if(b==1&&umb[bc]==0)
			cnt++;
		bc=a;
	}	
	printf("%d",cnt);
}
