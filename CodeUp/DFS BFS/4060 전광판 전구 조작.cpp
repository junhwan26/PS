#include<iostream>
using namespace std;
int in[100][100];
int check[100][100];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n,m;

int fill(int a, int b){
	check[a][b]=1;
	for(int i=0; i<4; i++){
		int na=a+dir[i][0],nb=b+dir[i][1];
		
		if(in[na][nb]!=in[a][b] || check[na][nb] || na>=n || nb>=m || na<0 || nb<0)
			continue;
		fill(na,nb);
	}
}

int main(){

	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>in[i][j];
		}
	}
	
	int on=0,off=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			
			if(!check[i][j]){
				fill(i,j);
				if(in[i][j]==1)
					off++;
				else
					on++;
			}
		}
	}
	
	cout<<on<<" "<<off;
		
}
