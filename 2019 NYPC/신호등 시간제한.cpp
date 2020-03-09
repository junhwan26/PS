#include<stdio.h>
#include<queue>

typedef struct dot
{
	int a, b, t;
}dot;
using namespace std;
queue<dot> q;
#define quM 1000000

int light[400][400];
int date[400][400];
int n, m, r, c;
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int cnt;


void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", date[i][j]);
		printf("\n");
	}
}

int check1()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (date[i][j] == 0)
				return 1;
	}
	return 0;
}

int main()
{
	int day;
	scanf("%d %d %d %d %d", &n, &m, &day, &r, &c);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &light[i][j]);
		}
	}

	push(r,c,0);

	while (cnt < n * m)
	{
		int tmp = q.size();
		printf("%d\n", tmp);
		for (int i = 0; i < tmp; i++)
		{
			int a = q.front().a, b = q.front().b, t = q.front().t,
			if (date[a][b] == 0)
			{
				date[a][b] = day;
				cnt++;
			}

			if (t < 3)
				q.push({a,b,t+1});

			int da = a + dir[(light[a][b] + day) % 4][0], db = b + dir[(light[a][b] + day) % 4][1];

			if (da >= n || db >= m || da < 0 || db < 0 || date[da][db])
				continue;
			push(da,db,0);

		}

		day++;
	}
	print();

}
