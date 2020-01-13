#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std; 
queue<int> q;
stack<int> st;
int v,e;
int graph[100][100];
int check[100];
int check2[100];
int c;
void bfs()
{

		q.push(c-'A');
		check[c-'A']=1;

	while(!q.empty())
	{
		int front=q.front();
		printf("%c",front+'A');
		q.pop();
		for(int j=0;j<v;j++)
		{
			if(graph[front][j]==1&&check[j]==0)
			{
				check[j]=1;
				q.push(j);
			}
		}
	}

}

void dfs()
{
	st.push(c-'A');
	
	while(!st.empty())
	{
		int top= st.top();
		st.pop();
		if(!check2[top]){
		printf("%c",top+'A');
		check2[top]=1;
		for(int j=v-1;j>=0;j--)
		{
			if(graph[top][j]==1&&check2[j]==0)
			{
				st.push(j);
			}
		}
		}
			
	}	
}

int main()
{
	scanf("%d %d",&v,&e);
	getchar();
	for(int i=0;i<e;i++)
	{
		char a,b;
		scanf(" %c",&a);
		scanf(" %c",&b);
		//printf("%d %d",a,b);
		graph[a-'A'][b-'A']=1;
		graph[b-'A'][a-'A']=1; 
	}
	
	scanf(" %c",&c);
	//printf("%c %d",c,c-'A');
	dfs();
	printf("\n");
	bfs();
}
