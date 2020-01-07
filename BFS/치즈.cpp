//floodfill
#include<stdio.h>
#include <memory.h>

int n,m,hour;
int in[102][102];
int h;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int check[100][100];

void outside(int a, int b)
{
	in[a][b]=-1;
	check[a][b]=1;
	for(int i=0;i<4;i++)
	{
		int na=a+dir[i][0],nb=b+dir[i][1];
		if(na>n||nb>m||na<=0||nb<=0||in[na][nb]!=0||check[na][nb]==1)
			continue;
		outside(na,nb);
	}
	check[a][b]=0;
}

void dfs(int a, int b)
{
	if(a>n||b>m||a<1||b<1||in[a][b]!=1)
	return;
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		int na=a+dir[i][0],nb=b+dir[i][1];
		if(na>=n||nb>=m||na<0||nb<0) continue;
		if(in[na][nb]==-1) cnt++;
	}
	if(cnt>=2)
		in[a][b]=2;
}

void print()
{
		for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
			printf("%2d",in[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main()
{
	memset(in,-1,sizeof(int)*102*102);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&in[i][j]);


	while(1)
	{
		int flag=0;
		outside(1,1);
		//print();
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(in[i][j]==1)
				{
					dfs(i,j);
				}
			}
		}
		
		//printf("변환\n");
		//print();
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(in[i][j]==2)
				{
					in[i][j]=0;
					flag=1;
				}
				if(in[i][j]==-1)
					in[i][j]=0;
			}
		}
		
		//printf("체크 %d\n",hour); 
		//print();
		
		if(flag==0)
			break;
		hour++;

		
	}
	printf("%d",hour);
	
}
