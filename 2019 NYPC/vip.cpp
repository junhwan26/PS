#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct card{
	int e,d,max;
};

bool comp(const card& s1, const card& s2)
{
	return (s1.max<s2.max);
}


vector<card> v;
 

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back({a,b,a+b});
	}
	
	sort(v.begin(),v.end(),comp);
	
	for(int j=0;j<n;j++)
	{
		printf("%d ",v[j].e);
	}
	cout<<endl;
	for(int j=0;j<n;j++)
	{
		printf("%d ",v[j].d);
	}
	cout<<endl;
	for(int j=0;j<n;j++)
	{
		printf("%d ",v[j].max);
	}	
	
	
}
