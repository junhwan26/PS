#include<stdio.h>
#include<queue>

using namespace std;

int map[101][101];

int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
int ans[101][101];

typedef struct dot{
	int x,y;
}dot;
	int n,m;
queue<dot> q;


int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
			if(i!=0||j!=0)
				ans[i][j]=100001;
		}
	}	
	dot a={0,0};
	q.push(a);

	while(!q.empty()){
		int size=q.size();
		
		for(int i=0;i<size;i++){
		
			
			dot temp=q.front();
			q.pop();

			if(temp.x==n-1&&temp.y==m-1)
			{
				continue;
			}
			
			

			for(int j=0;j<4;j++){
				int nx=temp.x+dir[j][0];
				int ny=temp.y+dir[j][1];
				int tmp;
				if(map[nx][ny]==1){
					tmp=ans[temp.x][temp.y]+1;

				}
				else{
					tmp=ans[temp.x][temp.y];
				}
				
				if(tmp>=ans[nx][ny]||nx>=n||nx<0||ny>=m||ny<0)
					continue;
				ans[nx][ny]=tmp;
				dot ndot={nx,ny};
				q.push(ndot);	
			}
		}
	}
	printf("%d",ans[n-1][m-1]);
	
}
