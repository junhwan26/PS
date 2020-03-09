#include<stdio.h>
#include<set>
#include<queue>


int check[100001][2];
int mem[100001];
using namespace std;


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &mem[i]);
	}
	
	
	for (int i = 1; i <= m; i++)
	{
		int flag = 0;
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);



		for (int j = a; j <= b; j++)
		{
			check[mem[j]][0]=1; 
		}
		
		for (int j = c; j <= d; j++)
		{
			check[mem[j]][1]=1;
		}
		
		
		for(int i=0;i<n;i++)
		{
			if(check[i][0]!=check[i][1])
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}
		
		for (int j = a; j <= b; j++)
		{
			check[mem[j]][0]=0; 
		}
		
		for (int j = c; j <= d; j++)
		{
			check[mem[j]][1]=0;
		}
		if(!flag)
			printf("YES\n");
	}

}
