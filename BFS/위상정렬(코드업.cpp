#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
int v,e; // 정점 개수, 변 개수 
using namespace std;
//vector<vector<int> > graph;
queue<int> graph[200];
queue<int> q;
int in[200];
int check[200];
void bfs(int n)
{
	check[n]=1;
	q.push(n);
	while(!graph[n].empty()) 
	{
		in[graph[n].front()]--;
		graph[n].pop();
	}
	for(int i=1;i<=v;i++)
	{
		if(in[i]==0&&check[i]==0)
			bfs(i);	
	}
	return;
}

int main()
{
	int a,b,n;
	scanf("%d %d",&v,&n);
	//printf("%d\n",v);
	//graph.resize(v+1);
	for(int i=0;i<n;i++) 
	{
		scanf("%d %d",&a,&b);
		graph[a].push(b);
		in[b]++;
	}

	for(int i=1;i<=v;i++)
	{
		if(in[i]==0)
			{
				bfs(i);
				break;
			}
	}
	
	for(int i=1;i<=v;i++)
	{
		if(in[i]!=0)
		{
			printf("-1");
			return 0;
		}
	}
	
	while(!q.empty())
	{
		printf("%d\n",q.front());
		q.pop();
	}
}
