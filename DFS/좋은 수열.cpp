#include<stdio.h>
#include<iostream>
#include<string> 
int n;
using namespace std;
void check(	string a)
{
	for(int j=1;j<=a.size()/2;j++)
	{
		for(int i=0;i<a.size()-2*j+1;i++)
		{
			if(a.substr(i,j)==a.substr(i+j,j))
				return;
		}
	}
	if(a.size()==n)
	{
		cout<<a;
		exit(0);
	}
	
	check(a+"1");
	check(a+"2");
	check(a+"3");
}
int main()
{
		scanf("%d",&n);
		string a="1";
		check(a);
}
