#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std; 


int main()
{
	queue<int> q;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		q.push(i);
	}
	while(q.size()>=3)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	if(q.size()==2)
	q.pop();
	cout<<q.front();
}
