#include<stdio.h>
#include<vector>
#include<algorithm>
int v,e; // 꼭지점 개수, 변 개수 
using namespace std;
vector<vector<int> > graph;
#include<queue>

queue<int> q;
int check[101];
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
	vector<vector<int> > res;

	for(int i=1;i<=v;i++)
	{
		if(check[i]==1)
		continue;
		res.push_back(vector<int>());
		q.push(i);
		check[i]=1;
		while(!q.empty())
		{
			tmp=q.front();
			res.back().push_back(tmp);
			for(int j=0;j<graph[tmp].size();j++)
			{
				int next = graph[tmp][j];
				if(check[next]==0)
				{
					q.push(next);
					check[next]=1;
				}
			}
			q.pop();
		}
	}	
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++)
	{
		sort(res[i].begin(),res[i].end());
		for(int j=0;j<res[i].size();j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
