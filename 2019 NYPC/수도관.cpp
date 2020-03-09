#include<stdio.h>
#include<queue>
#include<vector>
#include <iostream>
#include<algorithm>
using namespace std;
vector<pair<int, int> > v;
 deque<int> dq;
int n,e;
int cnt;

int main()
{
	scanf("%d %d",&n,&e);
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	
	int cnt=1; 
	sort(v.begin(), v.end());
	
	for(int i=0;i<n;i++)
	{
		int tmp=v[i].second;
		
		if(dq.empty())															//front가 최소 back이 최대 
			dq.push_back(tmp);
		if(dq.front()>tmp)
		{
			if(dq.back()-tmp<=2*e)		// 새로 안파도 됨 
			{
				if(dq.front()!=dq.back())
					dq.pop_front();
				dq.push_front(tmp);	
			}
			else
			{
				while(!dq.empty())
					dq.pop_back();
				dq.push_front(tmp);
				cnt++;
			}
		}
		else if(dq.back()<tmp)
		{
			if(tmp-dq.front()<=2*e)		// 새로 안파도 됨 
			{
				if(dq.front()!=dq.back())
				dq.pop_back();
				dq.push_back(tmp);	
			}
			else
			{
				while(!dq.empty())
					dq.pop_back();
				dq.push_front(tmp);
				cnt++;
			}			
		}
	}
	printf("%d",cnt);
}

