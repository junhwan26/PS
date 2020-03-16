#include<iostream>
#include<queue>
using namespace std;
int day[100][100][100];


int n,m,h;
int dir[6][3]={{0,0,1},{0,1,0},{1,0,0},{-1,0,0},{0,-1,0},{0,0,-1}};

typedef struct dot{
	int x,y,z;
};

queue<dot> q;


int main(){

	cin>>n>>m>>h;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				cin>>day[k][j][i];
				if(day[k][j][i]==1){
					q.push({k,j,i});
				}
					
			}
		}
	}
	
	int date=2;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			
			int a=q.front().x,b=q.front().y,c=q.front().z;
			q.pop();
			
			for(int j=0;j<6;j++){
				int na=a+dir[j][0],nb=b+dir[j][1],nc=c+dir[j][2];
				if(na>=n||nb>=m||nc>=h||na<0||nb<0||nc<0||day[na][nb][nc]!=0)
					continue;
				
				day[na][nb][nc]=date;
				q.push({na,nb,nc});
			}	
		

		
		
		}
		date++;
	}
		
	
	int ans=0, flag=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(day[k][j][i]==0){
					flag=1;
					ans=0;
					break;
				}
				ans=max(ans,day[k][j][i]);
			}
			if(flag)
				break;
		}
		if(flag)
			break;
	}
	cout<<ans-1;
	
	
}


