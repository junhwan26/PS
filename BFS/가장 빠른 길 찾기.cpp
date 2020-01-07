#include<stdio.h>
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
int in[100][100];
int check[100][100];
int min=10000;
int dir[5][2]={{1,0},{-1,0},{0,-1},{0,1},{0,0}};
void bfs(int a, int b, int cnt)
{
	//printf("%d %d %d\n",a,b,cnt);
	if(a==0&&b==m-1&&min>cnt)
	{
		min=cnt;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int na=a+dir[i][0],nb=b+dir[i][1];
		if(na>=n||nb>=m||na<0||nb<0||in[na][nb]==1||check[na][nb]==1)
			continue;
		check[na][nb]=1;
		bfs(na,nb,cnt+1);
		check[na][nb]=0;
	}
	
}
int main(){
	int i,j; 
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%1d",&in[i][j]);	
	
		
	bfs(n-1,0,1);
	if(min==10000) printf("-1");
	else
	printf("%d",min);
}
