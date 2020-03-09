#include<stdio.h>
#include<queue>
using namespace std;

queue<int> q;
int light[400][400];
int date[400][400];
int n, m, r, c;
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };



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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			date[i][j] = 99999999;
		}
	}

	date[r][c] = day;
	q.push(r);
	q.push(c);
	q.push(0);
	q.push(day);

	while (!q.empty())
	{
		//	print();
		//	printf("\n");
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		int w = q.front(); q.pop();
		int t = q.front(); q.pop();


		if (w < 4)
		{
			q.push(a);
			q.push(b);
			q.push(w + 1);
			q.push(t + 1);
		}

		int da = a + dir[(light[a][b] + t) % 4][0], db = b + dir[(light[a][b] + t) % 4][1];

		if (da < n && db < m && da >= 0 && db >= 0 && date[da][db] > date[a][b] + w + 1)
		{
			q.push(da);
			q.push(db);
			q.push(0);
			q.push(t + 1);
			date[da][db] = date[a][b] + 1 + w;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", date[i][j]);
		}
		printf("\n");
	}

}
