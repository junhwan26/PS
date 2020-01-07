#include<iostream>
#include<list>
#include<string.h>
#include <algorithm>
using namespace std;

char a[600000];
int main()
{
	scanf("%s",a);
	int n,i;
	scanf("%d",&n);
	list<char> v;
	char temp[4];
	
	for(int i=0; i<strlen(a); i++)
	{
		v.push_back(a[i]);
	}
	list<char>::iterator cur = v.end();
	list<char>::iterator cur2 = v.begin();
	cur2--;

	fflush(stdin);
	for(i=0;i<n;i++)
	{
		gets(temp);
		//printf("%c %c %c",temp[0],temp[1],temp[2]);
		//printf("%c\n",temp[0]);
		
		if(temp[0]=='L')
			if(cur!=v.begin())
				cur--;
		if(temp[0]=='B'&&cur!=v.begin())
		{
			list<char>::iterator tmp = cur;
			//cur++;
			tmp--;
			v.erase(tmp);	
		}
			
		if(temp[0]=='P')
		{
			//printf("p %c\n",temp[2]);
			v.insert(cur,temp[2]);
		}
		
		if(temp[0]=='D')
		{
			if(cur!=v.end())
				cur++;			
		}
	}
	
	for(list<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		printf("%c",*it);
	}
	

} 
