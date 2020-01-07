#include<stdio.h>
int in[500000];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}

	int a = 0, b = 0;

	for (int i = 1; i < n; i++)
	{
		if (in[i] > in[i - 1])
		{
			a = 1;
			break;
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		if (in[i] < in[i - 1])
		{
			b = 1;
			break;
		}
	}

	if (a == 0 || b == 0)
		printf("yes");
	else
		printf("no");
}
