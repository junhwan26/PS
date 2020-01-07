#include<stdio.h>
#include<stdio.h>
#include<vector>
using namespace std;
int n;
int tree[101];
vector<int> parenta;
vector<int> parentb;
int chona, chonb;
void pa(int a)
{
	if (a == 0) return;
	parenta.push_back(a);
	pa(tree[a]);
}

void pb(int a)
{
	if (a == 0) return;
	parentb.push_back(a);
	pb(tree[a]);
}

void find()
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
	chona=-1; chonb=0;
}

int main()
{
	scanf("%d",&n);
	int ga,gb,m;
	scanf("%d %d",&ga,&gb);
	scanf("%d",&m);
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		//printf("%d\n",a);
		tree[b]=a;
	}
	//for(int i=1;i<=n;i++)
	//printf("%d ",tree[i]);
	pa(ga);
	pb(gb);
	find();
	printf("%d",chona+chonb);
	
}
