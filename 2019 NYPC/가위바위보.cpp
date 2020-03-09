#include<stdio.h>
#include<vector>
using namespace std;
int parent[200001];
int team[200001];
int person[2][200001];
int n, m;
int root[200001];


int find(int x, int n) {
	if (parent[x] == x) {
		parent[n] = x;
		return x;
	}
	return parent[x] = find(parent[x], n);
}

void Union(int x, int y) {

	x = find(x, x);
	y = find(y, y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		person[0][a]++;
		person[1][b]++;
		Union(a, b);
	}
	/*
	for(int i=1;i<=n;i++)
		printf("%d ",parent[i]);
	printf("\n");
*/
	for (int i = 1; i <= n; i++)
	{
		root[i]=find(i,i);
	}
	
	for (int i = 1; i <= n; i++)
	{
		team[root[i]]++;
	}

	int teammax = 0, maxi;
	for (int i = 1; i <= n; i++)
	{
		if (team[i] > teammax)
		{
			teammax = team[i];
			maxi = i;
		}
	}
	int winmax = 0, wini;
	for (int i = 1; i <=n; i++)
	{
		if (root[i] == maxi)
		{
			if (person[0][i] > winmax)
			{
				winmax = person[0][i];
				wini = i;
			}
			else if (person[0][i] == winmax)
			{
				if (person[1][i] < person[1][wini])
				{
					winmax = person[0][i];
					wini = i;
				}
			}
		}
	}
	printf("%d", wini);

}
