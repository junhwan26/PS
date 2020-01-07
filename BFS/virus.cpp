#include<stdio.h>
int n, m;
using namespace std;

#include<vector>
vector<int> graph[101];
#include<queue>
int check[101];
queue<int> q;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	q.push(1);
	check[1] = 1;
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		int size = graph[now].size();
		for (int i = 0; i < size; i++)
		{
			int d = graph[now][i];
			if (check[d]) continue;
			check[d] = 1;
			q.push(d);
			//printf("%d ",d);
			cnt++;
		}

	}
	printf("%d", cnt);
}
