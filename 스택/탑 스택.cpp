#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int arr[500000];
int ans[500000];
int main()
{
	int n,tmp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	stack<int> s;
	
	for(i=n-1;i>=0;i--)
	{
		tmp=arr[i];
		//printf("%d ",i);
		if(s.empty()||arr[s.top()]>arr[i])
		{
			s.push(i);
		}
		else
		{
			//printf("else!\n");
			while(!s.empty()&&arr[s.top()]<arr[i])
			{
				ans[s.top()]=i+1;
				s.pop();
			}
			s.push(i);
		}
		
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",ans[i]);		
	}
}
