#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
priority_queue<int> mq;

void push(int a)
{
	if(a<0)
		mq.push(a);
	else
		pq.push(a);
}


int main()
{
	int n;
	scanf("%d",&n);
	//freopen("out.txt","w",stdout);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a)
		push(a);
		else
		{
			if(mq.empty()&&pq.empty())
			{
				printf("0\n");
				continue;
			}
			else if(mq.empty()&&!pq.empty())
			{	
				int tmp=pq.top();
				printf("%d\n",tmp);
				pq.pop();	
			}
			else if(!mq.empty()&&pq.empty())
			{
				int tmp=mq.top();
				printf("%d\n",tmp);
				mq.pop();	
				
			}
			else
			{
				int mtop=-mq.top(),ptop=pq.top();
				//printf("mtop = %d ptop = %d\n",mtop,ptop);
				if(mtop<=ptop)
				{
					printf("%d\n",-mtop);
					mq.pop();
				}
				else
				{
					printf("%d\n",ptop);
					pq.pop();
				}
			}
		}
	}
	
}
