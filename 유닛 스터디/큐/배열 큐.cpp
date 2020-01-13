#include<stdio.h>
#define N 50
int is_empty(int queue[N], int *f, int *r)
{
	if(*f-1==*r)	return 1;
	return 0;
}

void push(int queue[N],int *f, int *r, int data)
{
	queue[++*r]= data;
	
}

void pop(int queue[N],int *f, int *r)
{
	if(is_empty(queue,f,r))
	{
		printf("underflow\n");
		return;
	}
	queue[(*f)++]=0;
}

int front(int queue[N],int *f, int *r)
{
	if(is_empty(queue,f,r))
	{
		printf("is_empty\n");
		return -1;
	}
	return queue[*f];
}


int size(int queue[N],int *f, int *r)
{
	return *r-*f-1;
}

int print_queue(int queue[N],int *f, int *r)
{
	printf("queue : [");
	for(int i=*f;i<*r;i++)	printf("%d, ",queue[i]);
	if(!is_empty(queue,f,r))	printf("%d ",queue[*r]);
	printf("]\n");
}

int main()
{
	int q[N];
	int f=0, r=-1;
	print_queue(q,&f,&r);
	
	printf("q.push(%d)\n",1);
	push(q,&f,&r,1);
	
	int a=2;
	printf("q.push(a) : a value is %d\n",a);
	push(q,&f,&r,a);
	
	print_queue(q,&f,&r);
	
	printf("q.pop()\n");
	pop(q,&f,&r);
	
	printf("p.push(%d)\n",3);
	push(q,&f,&r,3);
	
	printf("q.front : %d\n",front(q,&f,&r));
	
	print_queue(q,&f,&r);
	return 0;
}
