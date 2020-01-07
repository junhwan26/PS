#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

stack<char> s;
char str[1000001];

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

	int i,n,j,tmp,a;
	
		scanf("%s",str);
		for(i=0;str[i]!=NULL;i++)
		{
			if(!empty()&&((top()=='('&&str[i]==')')||(top()=='['&&str[i]==']')||(top()=='{'&&str[i]=='}')))
				pop();
			else 
				push(str[i]);
		}
		if(empty())	printf("YES");
		else printf("NO");
		
		while(!empty())
			pop();

}
