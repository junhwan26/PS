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

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->left = root->right = NULL;
        root->Data = value;
        return root;
    }
    else
    {
        if(root->Data >= value)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
    }
    return root;
}

Node* search(Node* tree, int data)
{
	while (tree != NULL && tree->Data != data)
	{
		if (tree->Data > data)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}

	return tree;

}




void printbt(Node* bt)
{
	if (bt == NULL) return;
	printbt(bt->left);
	printf("%d ", bt->Data);
	printbt(bt->right);
}

Node* searchMinNode(Node* tree)
{
	if (tree == NULL)
		return NULL;
	if (tree->left == NULL)
		return tree;
	return searchMinNode(tree->left);
}

Node* searchMaxNode(Node* tree)
{
	if (tree == NULL)
		return NULL;
	if (tree->right == NULL)
		return tree;
	return searchMaxNode(tree->right);
}
int flag;

Node* del(Node* root, int data)
{
    Node* tNode = NULL;
    if(root == NULL)
    {
		printf("NOT FOUND");
		flag=1;
        return NULL;
	}
    if(root->Data > data)
        root->left = del(root->left, data);
    else if(root->Data < data)
        root->right = del(root->right, data);
    else
    {
        if(root->right != NULL && root->left != NULL)
        {
            tNode = searchMinNode(root->right);
            root->Data = tNode->Data;
            root->right = del(root->right, tNode->Data);
            return root;
        }
        else
        {
            tNode = (root->left == NULL) ? root->right : root->left;
            free(root);
            return tNode;
        }
    }
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
			tree=insert(tree, m);
			printbt(tree);
			printf("\n");
		}
		if (!strcmp(a, "delete"))
		{
			tree=del(tree, m);
			if(!flag)
			{	
				printbt(tree);
				flag=1;	
			}
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
