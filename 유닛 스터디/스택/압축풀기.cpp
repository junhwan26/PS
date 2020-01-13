#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char arr[1000001];
int TOP=0;

int empty()
{
	if(TOP==0)
		return 1;
	return 0;
	
}

int top()
{
	return arr[TOP-1];
}

void pop()
{
	TOP--;
	return;
}

void push(char a)
{
	arr[TOP++]=a;
	return;
}

int main()
{
	string str;
	cin>>str;
	string tmp;
	
	int i;
	for(i=0;i<str.length();i++)
		push(str[i]);
	while(empty())
	{
		if(str[i]==')'||str[i]=='(')
		{
			
		}
		else
		{
			
		}
	}
	
	 if(str[0]=='h')
	cout<<str;
	cout<<int(str[1]);
}
