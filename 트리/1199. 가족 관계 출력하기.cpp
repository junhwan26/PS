#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char name[100][11];
int tree[101];
int cnt[100];
vector<int> parenta;
vector<int> parentb;
int chona, chonb;
int namenum(char n[11])
{
	for (int i = 0; i < 100; i++)
	{
		//printf("%s 비교중 %s\n",n,name[i]);
		if (!strcmp(n, name[i]))
			return i + 1;
	}
	return -1;
}
void findparenta(int a)
{
	if (a == -1) return;
	parenta.push_back(a);
	findparenta(tree[a]);

}

void findparentb(int a)
{
	if (a == -1) return;
	parentb.push_back(a);
	findparentb(tree[a]);

}

void gg()
{
	for (int i = 0; i < parenta.size(); i++)
	{
		for (int j = 0; j < parentb.size(); j++)
		{
			if (parentb[j] == parenta[i])
			{
				chona = i; chonb = j;
				return;
			}
		}
	}
}
void printtree()
{
	for (int i = 1; i <= 15; i++)
		printf("%d ", tree[i]);
	printf("\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	int i=0;
	for (int j = 0; j < n; j++)
	{
		char tmp1[11], tmp2[11];
		scanf("%s %s", tmp1, tmp2);
		getchar();
		int num1 = namenum(tmp1), num2 = namenum(tmp2);
		//printf("%s의 num은 %d\t%s의 num은 %d\n",tmp1,num1,tmp2,num2);
		if (num1 == -1)
		{

			tree[i + 1] = -1;
			strcpy(name[i], tmp1); i++;
			strcpy(name[i], tmp2);
			num1 = namenum(tmp1); num2 = namenum(tmp2);
			tree[num2] = num1;
		}
		else
		{
			if (num2 == -1)
			{
				tree[i+1] = num1;
				strcpy(name[i], tmp2);
			}
			else if (tree[num2] == -1)
			{
				tree[num2] = num1;
				i--;
			}
		}
		i++;
	 //printtree();
	}



	char a[11], b[11];
	scanf("%s %s", a, b);
	getchar();
	int anum = namenum(a), bnum = namenum(b);
	findparenta(anum);
	findparentb(bnum);
	gg();
	/* //디버깅 

	printf("\nanum = %d bnum = %d\n", anum, bnum);
	printf("a의 조상들: ");
	for (int i = 0; i < parenta.size(); i++)
	{
		printf("%d ", parenta[i]);
	}
	printf("\n");
	printf("b의 조상들: ");
	for (int i = 0; i < parentb.size(); i++)
	{
		printf("%d ", parentb[i]);
	}
	printf("\nchona = %d chonb = %d\n", chona, chonb);
	//*/


	if (chona == 1 && chonb == 1)
		printf("Sibling");
	else if (chona == 2 && chonb == 2)
		printf("Cousin");
	else if (chona == 0 && chonb == 1)
		printf("Parent");
	else if (chona == 0 && chonb == 2)
		printf("Grand Parent");
	else if (chonb == 0 && chona == 1)
		printf("Child");
	else if (chonb == 0 && chona == 2)
		printf("Grand Child");
	else
	{
		printf("No Relation");
	}


}
