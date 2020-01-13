#include<stdio.h>
#include<vector>
int parent[300010];
int check[300010];
int n,l;
	
int find(int a)
{
	if(parent[a]==a)
		return a;
	return find(parent[a]);	
}

void setp(int a, int b)
{
	int pa=find(a),pb=find(b);
	parent[pa]=pb;
	printf("LADICA\n");
}

int main()
{
	//freopen("out.txt","w",stdout);
	scanf("%d %d",&n,&l);
	for(int i=1;i<=l;i++)
		parent[i]=i;
	for(int j=0;j<n;j++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(!check[a])
		{
			check[a]=1;
			setp(a,b);
		}
		else if(!check[b])
		{
			check[b]=1;
			setp(b,a);
		}
		else if(!check[find(a)])
		{
			check[find(a)]=1;
			setp(a,b);
		}
		else if(!check[find(b)])
		{
			check[find(b)]=1;
			setp(b,a);
		}
		else
			printf("SMECE\n");
	}
}

