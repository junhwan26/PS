#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
int v,e; // 꼭지점 개수, 변 개수 
using namespace std;
vector<vector<int> > graph;
vector<vector<int> > res;
int check[20001];
#include<queue>
queue<int> q;

int main()
{
	scanf("%d %d",&v,&e);
	graph.resize(v+1);
	for(int i=0,a,b;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int tmp;
	for(int i=1;i<=v;i++)
	{
		if(check[i]!=0)
			continue;
		q.push(i);
		check[i]=1;
		while(!q.empty())
		{
			tmp=q.front();
			for(int j=0;j<graph[tmp].size();j++)
			{
				int next = graph[tmp][j];
				//printf("i= %d j= %d next= %d\n",i,j,next);
				if(check[next]==0)
				{
					q.push(next);
					check[next]=3-check[tmp];
				}
				else
				{
					if(check[next]==check[tmp])
					{
						printf("NO\n");
						return 0;	
					}
				}
			}
			q.pop();
				
		}		
	}
	printf("YES");
	
	
}
