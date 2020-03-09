#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int in[1002][1002];
int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
int check[1002][1002];


typedef struct dot{
	int a,b,ans;
}dot;

queue<dot> q;


int main(){
	int ans=9999999;
	int n,m, flag=0;

	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>in[i][j];
		}
	}
	
	check[1][1]=1;
	dot first={1,1,1};
	q.push(first);

	while(!q.empty()){

		int a=q.front().a,b=q.front().b,tmp=q.front().ans; 
		q.pop();
			
		if(a==n&&b==m){
			ans=tmp;
			break;
		}
			
			
		for(int i=0;i<4;i++){
		
			int na=a+dir[i][0],nb=b+dir[i][1];
		
			if( check[na][nb] || !in[na][nb] || abs(in[na][nb]-in[a][b])>1 )
				continue;
			
			dot temp={na,nb,tmp+1};
			q.push(temp);
			check[na][nb]=1;
		}
		
		
	}
	if(ans!=9999999)
		cout<<ans;
	else
		cout<<"0";
}

