#include<stdio.h>
#include<queue>
using namespace std;

typedef struct dot{
	int a,b,w;
};

queue<dot> q;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int in[1001][1001];
int check[1001][1001][2];

int main(){
	int n,m;
	scanf("%d %d",&n,&m); 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&in[i][j]);
	
	q.push({1,1,0});
	check[1][1][0]=1;
	
	int ans=1;
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			int a=q.front().a,b=q.front().b,w=q.front().w; 
			q.pop();
		
		
			if(a==n&&b==m){
				printf("%d",ans);
				return 0;
			}
			
			for(int i=0;i<4;i++){
					int na=a+dir[i][0],nb=b+dir[i][1];
	
					if(na>n || nb>m || na<1 || nb<1)
						continue;
				
					if(in[na][nb] && !w){
						q.push({na,nb,w+1});
						check[na][nb][w+1]=1;
					}
					else if(!in[na][nb] && !check[na][nb][w]){
						q.push({na,nb,w});
						check[na][nb][w]=1;
					}
			}
		
			
		}
		
		ans++;

	}	
	printf("-1");
}
