#include<stdio.h>
int in[400][3];
int check[400];
int graph[400][400];
#include<map>
using namespace std;

int abs(int a)
{
	return a>0?a:-a;
}
int main()
{
	int R,B; //R=0, B=1
	scanf("%d %d",&R,&B);
	for(int i=0;i<R;i++)
	{
		in[i][2]=1;
		scanf("%d %d",&in[i][0],&in[i][1]);
	}
	for(int i=R;i<B+R;i++)
	{
		in[i][2]=-1;
		scanf("%d %d",&in[i][0],&in[i][1]);
	}
	int n=R+B;
	printf("%d\n",n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		map<int, int> m;
		for(int j=0;j<n;j++)
		{
			
			int tmp=abs(in[i][0]-in[j][0])+abs(in[i][1]-in[j][1]);
			map[tmp]=j;
			//printf("%d ",tmp);
		}
		int d=0;
		iter = m.begin()
		check[iter->first]++;
		if(check[iter->first]>2&&(in[iter->first][2]*in[i][2]==1))
		{
			printf("-1");
			return;
		}
		ans+=check[iter->second];
		iter++;
        
	
		//printf("\n");
	}
	
		
}
