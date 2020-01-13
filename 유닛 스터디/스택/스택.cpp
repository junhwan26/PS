#include<stdio.h>

int TOP=0,arr[1000];


int isempty()
{
	if(TOP==0)
		return 1;
	return 0;
}

void pop()
{
	if(!isempty())
		TOP--;
	else
		printf("underflow");	
	return ;
}

void push(int data)
{
	arr[TOP++]=data;
	return;
}

int size()
{
	return TOP;
}
int top()
{
	return arr[TOP-1];
}

int main()
{
	push(1);
	push(2);
	printf("%d ",top());
	pop();
	printf("%d ",top());
	pop();
	pop();
}
