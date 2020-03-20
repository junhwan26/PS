#include<stdio.h>
#include<queue>
using namespace std;

typedef struct dot{
	int a, b;
};

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int in[101][101];
int check[101][101];
queue<dot> q;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&in[i][j]);
	
	q.push({1,1});
	check[1][1]=1;
	int ans=0;
	
	while(!q.empty()){
		ans++;
		int size=q.size();
		for(int i=0;i<size;i++){
			int a=q.front().a,b=q.front().b;
			q.pop();
			if(a==n&&b==m){
				printf("%d",ans);
				return 0;
			}
			
			for(int i=0;i<4;i++){
				int na=a+dir[i][0],nb=b+dir[i][1];
		
				if(!in[na][nb] || check[na][nb] || na>n || nb>m||na<1||nb<1)
					continue;
				q.push({na,nb});
				check[na][nb]=1;
			}
		}
	}
}

