#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>
#include<stdlib.h>;
using namespace std;
vector<char> tree[1000];
string s;
int b = 0;

typedef struct node
{
	char data;
	struct node* fst;
	struct node* snd;
	struct node* trd;
	struct node* fth;
	struct node* parent;
}Node;

typedef struct tree
{
	Node* tnode;
}Tree;


void printqt(Node* t)
{
	if (t == NULL) return;
	printf("%c", t->data);
	printqt(t->fst);
	printqt(t->snd);
	printqt(t->trd);
	printqt(t->fth);
}
void reverseqt(Node* t)
{
	if (t == NULL) return;
	if (t->data != 'w' && t->data != 'b' && t->data != 'x') return;
	printf("%c", t->data);
	reverseqt(t->trd);
	reverseqt(t->fth);
	reverseqt(t->fst);
	reverseqt(t->snd);
}

void remove(Node *t)
{
	if(t==NULL) return;
	remove(t->fst);
	remove(t->snd);
	remove(t->trd);
	remove(t->fth);
	free(t);
}

int main()
{
	int cnt = 0;
	int n;
	scanf("%d", &n);
	
	for (int j = 0; j < n; j++)
	{
		cin >> s;
		Tree* tree = (Tree*)malloc(sizeof(Tree));
		tree->tnode==NULL;
		Node* cur = tree->tnode;
		Node* prev = cur;
		//Node *pprev = prev;
		for (int i = 0; i < s.size(); i++)
		{
			Node* tmp = (Node*)malloc(sizeof(Node));
			tmp->fst = NULL;
			tmp->snd = NULL;
			tmp->trd = NULL;
			tmp->fth = NULL;
			tmp->data = s[i];
			cur=tmp;
			if (s[i] == 'x')
			{
				cur=cur->fst;
				prev = cur;
				cur->parent = prev;
			}
			else
			{
				while(cur!=NULL)
				{
					if (prev->fst == cur)
					{
						cur=prev->snd;
					}
					else if (prev->snd == cur)
					{
						cur = prev->trd;
					}
					else if (prev->trd == cur)
					{
						cur = prev->fth;
					}
					else if (prev->fth == cur)
					{
						cur=prev;
						prev=prev->parent;
					}
				}
					
			}
		}
	}
		//printqt(tree);
		reverseqt(tree->tnode);
		printf("\n");
		remove(tree->tnode);
}
