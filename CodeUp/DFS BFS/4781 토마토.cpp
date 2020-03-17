#include<iostream>
#include<queue>
using namespace std;
int day[1000][1000];


int n,m;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

typedef struct dot{
	int x,y;
};

queue<dot> q;


int main(){

	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>day[i][j];
			if(day[i][j]==1){
				q.push({i,j});
			}
		}
	}
	
	int date=2;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			
			int a=q.front().x,b=q.front().y;
			q.pop();
			
			for(int j=0;j<4;j++){
				int na=a+dir[j][0],nb=b+dir[j][1];
				if(na>=m||nb>=n||na<0||nb<0||day[na][nb]!=0)
					continue;
				
				day[na][nb]=date;
				q.push({na,nb});
			}	

		}
		date++;
	}
		
	
	int ans=0, flag=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(day[i][j]==0){
				flag=1;
				ans=0;
				break;
			}
			ans=max(ans,day[i][j]);
		}
			
		if(flag)
			break;
	}
	cout<<ans-1;
	
	
}


