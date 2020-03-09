#include <iostream>
#include<stdio.h>

#define swap(a,b,temp) temp=a; a=b; b=temp;
int n;
using namespace std;
int maaax, exp[15][2], check[15];

int day = 0;
void permutations(int* a, const int k, const int m)
{
	int i;
	int temp;
	int tmp = 0;

	if (k == m)
	{
		for (i = 0; i <= m; i++)
		{	
		//	printf("%d %d %d\n",exp[a[i]][0],exp[a[i]][1] ,tmp);
			if (tmp<exp[a[i]][0])
			{
				tmp +=exp[a[i]][1];
			
			}
				
		}
		if (maaax < tmp)
			maaax = tmp;
	/*	for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n%d\n", tmp);*/
	}

	else
	{
		for (i = k; i <= m; i++)
		{
			swap(a[k], a[i], temp);
			permutations(a, k + 1, m);
			swap(a[k], a[i], temp);
		}

	}
}

int main()
{

	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		arr[i] = i;;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&exp[i][0] ,&exp[i][1]);
	}

	permutations(arr, 0, n - 1);
	cout << maaax;
}
