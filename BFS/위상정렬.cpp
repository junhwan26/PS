#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
int v,e; // 정점 개수, 변 개수 
using namespace std;
queue<int> ans;
queue<int> q;
int in[100];
int check[100];
int arr[101][101];
vector<int> A;
int main()
{
	int a,b;
	scanf("%d",&v);
	while(~scanf("%d %d",&a,&b)) 
	{
		arr[a][b]=1;
		//graph[a].push(b);
		in[b]++;
	}

	
	while(1)
	{
		int flag=1;
		for(int i=1;i<=v;i++)
		{	
			if(in[i]==0 && !check[i])
			{
				q.push(i);
				check[i]=1;
				flag=0;
			}
		}
		if(flag&&q.empty()) break;
		
		int qsz=q.size();
		for(;qsz--;)
		{
			int here=q.front();
			A.push_back(here);
			q.pop();
			for(int i=1;i<=v;i++)
			{
				if(arr[here][i]==1)
					in[i]--;
			}
			
		}
	}
	
	
	for(int i=1;i<=v;i++)
	{
		if(in[i]!=0)
		{
			printf("impossible");
			return 0;
		}
	}
	
	for(int i=0;i<A.size();i++)
	{
		printf("%d ",A[i]);
	}
}
