#include<iostream>
using namespace std;
int in[11][11];
int map[10][10];
int check[10][10];
int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{-1,1},{1,1},{-1,-1},{1,-1}};

void dfs(int a, int b){
	check[a][b]=1;
	
	if(map[a][b]!=0)
		return;
	
	for(int i=0;i<8;i++){
		int na = a+dir[i][0], nb = b+dir[i][1];
		if(na<1||nb<1||na>9||nb>9||check[na][nb])
			continue;
		dfs(na,nb);
	}
}

int main(){
	int a,b;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			cin>>in[i][j];
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			map[i][j]=in[i-1][j-1]+in[i][j-1]+in[i-1][j]
			+in[i+1][j+1]+in[i+1][j]+in[i][j+1]+in[i-1][j+1]+in[i+1][j-1];
		}	
	}
	
	cin>>a>>b;
	
	if(in[a][b]==1){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(j==a&&b==i)
					cout<<"-1 ";
				else
					cout<<"_ ";
			}
			cout<<"\n";
		}
		return 0;
	}
		
	dfs(a,b);
	
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(check[i][j])
				cout<<map[i][j]<<" ";
			else
				cout<<"_ ";
		}	
		cout<<"\n";
	}

}
