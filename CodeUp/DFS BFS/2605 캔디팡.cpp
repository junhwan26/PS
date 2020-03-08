#include<iostream>
using namespace std;

int in[9][9];
int check[8][8];	// 한번 방문했던 곳 체크 
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};	// 방향배열 

int ans;

int search(int a,int b){  //flood fill 재귀 구현 

	check[a][b]=1;
	int cnt=1;
	for(int i=0;i<4;i++){
		int na=a+dir[i][0], nb=b+dir[i][1];
		
		if(check[na][nb]||!in[na][nb])
			continue;
		
		if(in[na][nb]==in[a][b])
			cnt+=search(na,nb);
	}
	
	return cnt;
}

int main(){
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			cin>>in[i][j];
		}
	}
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			if(search(i,j)>=3)
				ans++;
		}
	}
	
	cout<<ans;
}
