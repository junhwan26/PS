#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct List{
	Node *head, *tail;
}List;

Node *new_Node(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->next=NULL;
	node->data=data;
	return node;
}

List *new_List()
{
	List *list = (List*)malloc(sizeof(List));
	list->head=list->tail=NULL;
	return list;
 } 
 
 void Insert(List *list, int data)
 {
 	Node *p = list->head;
 	while(p->next!=p) p=p->next;
 	Node *node= new_Node(data);
 	p->next=node;
 	list->tail=node;
 	list->tail->next=list->head;
	return;
 }
 
 void Delete(Node *node1, Node *node2)
 {
 	printf("%d ",node2->data);
 	node1->next=node2->next;
 }
 
int main()
{
	int n,m,k,i;
	scanf("%d %d %d",&n,&m,&k);
	List *list=new_List();
	printf("1");
	for(i=1;i<=n;i++)
		Insert(list,i);
	Node *p=list->head;
	while(p->next!=p)
	{
		printf("%d",p->data);
	}
	while(m>1)
	{
		p=p->next;
		m--;
	}
	Delete(p,p->next);
	while(p->next!=p)
	{
		for(i=0;i<k-1;i++)
		p=p->next;
		Delete(p,p->next);
	}
	printf("\n%d",p->data);
}
