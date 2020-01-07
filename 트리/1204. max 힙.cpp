#include<stdio.h>
#include<queue>
using namespace std;

priority_queue<int> pq;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==0)
		{
			int b;
			scanf("%d",&b);
			pq.push(b);
		}
		if(a==1)
		{
			if(!pq.empty())
			{
				printf("%d\n",pq.top());
				pq.pop();
			}
			else
				printf("-1\n");
		}
		if(a==2)
		{
			if(!pq.empty())
				printf("%d\n",pq.top());
			else
				printf("-1\n");
		}
	}
}
