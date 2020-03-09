#include <stdio.h>

int max;
int dal[1001][1001];
int i;
int x = 0;
int y = -1;
int t = 1;
int p;
int cnt = 1;
int jmax;
int n;
int  main()
{

	scanf("%d", &p);
	scanf("%d", &n);
	max = p;

	jmax = max;
	while (0 <= jmax)
	{
		for (i = 0; i < jmax; i++) //행 표현
		{
			y = y + t;
			dal[x][y] = cnt;
			cnt++;
		}
		jmax--;
		for (i = 0; i < jmax; i++)// 열 표현
		{
			x = x + t;
			dal[x][y] = cnt;
			cnt++;
		}
		t = t * -1;
	}

	for (int k = 0; k < p; k++)
	{
		for (int j = 0; j < p; j++)
		{
			if (dal[k][j] == n)
				printf("%d %d", j + 1, k + 1);
		}
	}

	return 0;
}

