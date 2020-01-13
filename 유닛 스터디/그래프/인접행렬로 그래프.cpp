#include<stdio.h>
int v,e; // 꼭지점 개수, 변 개수 
int graph[1001][1001]; // 그래프 정보를 저장하는 인접행렬 

int main()
{
	scanf("%d %d",&v,&e);
	for(int i =0,a,b;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a][b] = graph[b][a] = 1; // 꼭지점 a,b 사이의 변 연결 
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}	
 } 
