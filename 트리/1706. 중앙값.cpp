#include<queue>
#include<stdio.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	freopen("out.txt","w",stdout);
	for(int i=0;i<T;i++)
	{	
		int n;
		int cnt=0;
		priority_queue<int> maxh;
		priority_queue<int,vector<int>,greater<int> > minh;
		scanf("%d",&n);
		int mid;
		printf("%d\n",n/2+1);
		scanf("%d",&mid);
		printf("%d ",mid);
		cnt++;
		for(int j=2;j<=n;j++)
		{
			int a;
			scanf("%d",&a);
			if(a>mid)
			{
				minh.push(a);
			}
			else
			{
				maxh.push(a);
			}
			if(j%2==1)
			{	
				while(maxh.size()!=minh.size())
				{
					if(maxh.size()>minh.size())
					{
						minh.push(mid);
						mid=maxh.top();
						maxh.pop();					
					}
					else
					{
						maxh.push(mid);
						mid=minh.top();
						minh.pop();					
					}
				}
				printf("%d ",mid);
				cnt++;
			if(cnt%10==0)
			printf("\n");
			}
		}
		printf("\n");
	}
}
