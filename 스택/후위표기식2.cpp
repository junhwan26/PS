#include<stdio.h>
#include<string.h>
#include<memory.h>
#include <stdlib.h>
typedef struct node
{
	int Data;
	struct node* left;
	struct node* right;
}Node;


void insert(Node** tree, int data)
{
	Node* cur = *tree;
	Node* t = (Node*)malloc(sizeof(Node));
	t->left = NULL;
	t->right = NULL;
	t->Data = data;
	Node* prev;
	if (*tree == NULL)
	{
		*tree = t;
	}
	else
	{
		while (cur != NULL )
		{
			prev = cur;
			if (data >= cur->Data)
			{
				cur = cur->right;
			}
			else
			{
				cur = cur->left;
			}
		}
		
		if (prev->Data >= data)
			prev->left = t;
		
		else
			prev->right = t;
			
	}
}

Node* search(Node* tree, int data)
{
	while (tree != NULL && tree->Data != data)
	{
		if(tree->Data<0)
		{
			if (-tree->Data >= data)
			{
				tree = tree->left;
			}
			else
			{
				tree = tree->right;
			}
		}
		else
		{
			if (tree->Data >= data)
			{
				tree = tree->left;
			}
			else
			{
				tree = tree->right;
			}
		}
	}

	return tree;

}

void printbt(Node* bt)
{
	if (bt == NULL) return;
	printbt(bt->left);
	if(bt->Data>0)
	printf("%d ", bt->Data);
	printbt(bt->right);
}

void del(Node** tree, int data)
{
	Node* tmp = search(*tree, data);
	if (tmp == NULL)
	{
		printf("NOT FOUND");
		return;
	}
	else
	{
		tmp->Data=-tmp->Data;
	}

	printbt(*tree);
}




int main()
{
	Node* tree = (Node*)malloc(sizeof(Node));
	tree = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char a[50];
		int m;
		scanf("%s %d", a, &m);

		if (!strcmp(a, "insert"))
		{
			insert(&tree, m);
			printbt(tree);
			printf("\n");
		}
		if (!strcmp(a, "delete"))
		{
			del(&tree, m);
			printf("\n");

		}
		if (!strcmp(a, "search"))
		{
			Node* tmp = search(tree, m);
			if (tmp == NULL)
				printf("NO\n");
			else
				printf("YES\n");

		}
	}

}
