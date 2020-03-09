#include<set>
#include<stdio.h>
#include<algorithm>
using namespace std;

int in[100001];
int check[100001];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&in[i]);
	}
	for(int j=0;j<m;j++)
	{
		int a,b,c;
		scanf("%d %d %d",&c,&a,&b);
		if(c==1)
		{
			in[a-1]=b;
		}
		if(c==2)
		{
			set<int> s;
			for(int i=a-1;i<b;i++)
			{
				
				set<int>::iterator iter= s.find(in[i]);
				if(iter!=s.end())
					continue;
				int cnt=count(in+a-1,in+b,in[i]);
			//	printf("cnt=%d\n",cnt);
				if(cnt&1==1)
				{
					printf("%d\n",in[i]);
					break;
				}
				else{
					s.insert(in[i]);
				}	
			}
		}
		
	}
	
}
