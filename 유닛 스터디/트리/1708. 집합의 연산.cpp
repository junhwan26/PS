#include<stdio.h>
int parent[1000001];


int find(int a)
{
	if(parent[a]==0)
		parent[a]=a;
	if(parent[a]==a)
		return a;
	return find(parent[a]);	
}


void p(int a, int b)
{
	int pa=find(a),pb=find(b);
	parent[pa]=pb;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,a,b;
		scanf("%d %d %d",&x,&a,&b);
		if(x==0)
		{
			p(a,b);
		}
		else
		{
			if(find(a)==find(b))
			printf("YES\n");
			else
			printf("NO");
		}
	}
}
