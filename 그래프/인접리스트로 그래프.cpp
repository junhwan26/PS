#include<stdio.h>
#include<vector>
#include<algorithm>
int v,e; // 꼭지점 개수, 변 개수 
using namespace std;
vector<vector<int> > graph;

int main()
{
	scanf("%d %d",&v,&e);
	graph.resize(v+1);
	for(int i=0,a,b;i<e;i++)
	{
		scanf("%d %d",&a,&b);
 		if(a!=b)
			graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=1;i<=v;i++)
	{
		sort(graph[i].begin(),graph[i].end());
		printf("%d ",i);
		for(int j=0;j<graph[i].size();j++)
		{
			printf("- %d ",graph[i][j]);
		}
		printf("\n");
	}	
}
