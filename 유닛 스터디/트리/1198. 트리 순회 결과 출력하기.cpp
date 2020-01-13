#include<stdio.h>
int tree[27][2];
using namespace std;
void po(int i)
{
	if(!i||i+'A'-1=='.') return;
	printf("%c",i+'A'-1);
	po(tree[i][0]);
	po(tree[i][1]);
}

void in(int i)
{
	if(!i||i+'A'-1=='.') return;
	in(tree[i][0]);
	printf("%c",i+'A'-1);
	in(tree[i][1]);
}

void pr(int i)
{
	if(!i||i+'A'-1=='.') return;
	pr(tree[i][0]);
	pr(tree[i][1]);
	printf("%c",i+'A'-1);
}



int main()
{
	int n;
	scanf("%d", &n);
	getchar();;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		getchar();
		int p = a-'A'+1, l = b-'A'+1, r = c-'A'+1;

		if (l != '.')
			tree[p][0] = l;
		if (r != '.')
			tree[p][1] = r;
	}

	po(1);
	printf("\n");
	in(1);
	printf("\n");
	pr(1);
}
