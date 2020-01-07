#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101] ;
#include<deque>
#include<queue>
deque<int> dq;
queue<int> q;


int main()
{
	int n;
	scanf("%d",&n);
	int tmp;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	vector<int> res;
	for(int i=1;i<=n;i++)
	{
		tmp=i;
		for(int j=0;j<110; j++)
		{
			tmp=arr[tmp];
			if (tmp == i)
			{
				res.push_back(i);
				break;
			}
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++)
	printf("%d\n",res[i]);	
}
