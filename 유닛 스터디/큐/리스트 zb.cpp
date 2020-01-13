#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
}Node;

Node *new_node(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node -> link = NULL;
	return node;
}

typedef struct queue
{
	Node *front, *rear;
}queue;

queue *new_queue()
{
	queue *que=(queue*)malloc(sizeof(queue));
	que->front = que->rear = NULL;
	return que;
}

int is_empty(queue *q)
{
	return q->front == NULL && q->rear==NULL;
}

void push(queue *q,int data)
{
	Node *node = new_node(data);
	if(is_empty(q))
	{
		q->front=q->rear=node;
	}
	else 
	{
		q->rear->link=node;
		q->rear = node;
	}
}

void pop(queue *q)
{
	if(is_empty(q))
	{
		printf("is_empty\n");
		return;
	}
	Node *ele = q->front;
	q->front = ele->link;
	free(ele);
}

int front(queue *q)
{
	if(is_empty(q))
	{
		printf("q.front is not exist\n");
		return -1;
	}
	return q->front->data;
}

int main()
{
	queue *q= new_queue();
	printf("push %d\n",1);
	push(q,1);
	int a=2;
	printf("push a = %d\n",a);
	push(q,a);
	printf("push %d\n", 3);
	push(q,3);
	
	printf("front = %d\n",front(q));
	
	printf("pop\n");
	pop(q);
	
	printf("front = %d\n",front(q));
	return 0;
}
