#include<iostream>
#include<stdio.h>
#include<deque>
using namespace std; 


int arr[5000001];

int main()
{
	deque<int> dq;

	int n,l,i;
	scanf("%d %d",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	}
	
	for(i=0;i<n;i++)
	{
		if(dq.empty())	dq.push_back(arr[i]);
		else
		{
			while(!dq.empty()&&arr[i]<dq.back())
			{
				dq.pop_back();
			}
			if(i>=l&&arr[i-l]==dq.front())
			dq.pop_front();
		dq.push_back(arr[i]);
		}		
		printf("%d ",dq.front() );
	}
		
}
