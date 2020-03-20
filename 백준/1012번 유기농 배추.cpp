#include<iostream>
using namespace std;

int n,m;
int in[50][50];
int check[50][50];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void fill(int a, int b){
	check[a][b]=1;
	for(int i=0;i<4;i++){
		int na=a+dir[i][0],nb=b+dir[i][1];
		
		if(!in[na][nb] || check[na][nb] || na>=n || nb>=m||na<0||nb<0)
			continue;
		
		fill(na,nb);
	}
}

int main(){
	int x;
	cin>>x;
	for(int q=0;q<x;q++){
		int c,ans=0;
		cin>>m>>n>>c;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				in[i][j]=0;
				check[i][j]=0;
			}
				
		}
		
		for(int i=0;i<c;i++){
			int a,b;
			cin>>a>>b;
			in[b][a]=1;
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(in[i][j]&&!check[i][j]){
					fill(i,j);
					ans++;
				}

			}
		}
		cout<<ans<<"\n";
		
	}
}
