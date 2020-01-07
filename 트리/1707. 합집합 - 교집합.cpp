#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

bool check[100000001];

vector<int> A;

int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		A.push_back(tmp);
		check[tmp]=true;
	}
	
	for(int i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(!check[tmp])
			A.push_back(tmp);
		else
		{
			cnt++;
		}
	}
	
	printf("%d",A.size()-cnt);
}
