#include<stdio.h>

int N, ans;
int X[10], ld[20], rd[20];

void f(int y)
{
	if (y == N)
	{
		ans++;
		return;
	}
	for(int x=0; x<N; x++)
	{
		if (X[x] == 1 || ld[x+y]==1||rd[x-y+N]==1) continue;
		X[x]=1; ld[x+y]=1; rd[x-y+N]=1;
		f(y+1);
		X[x]=0; ld[x+y]=0; rd[x-y+N]=0;
	}
}

int main()
{
	scanf("%d", &N);
	f(0);
	printf("%d",ans);
}
