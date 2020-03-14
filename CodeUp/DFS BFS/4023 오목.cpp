#include<iostream>
using namespace std;

int dir[8][2]={{1,0},{0,1},{1,1},{-1,1}};
int in[20][20];
int check[20][20][4];

int dfs(int a, int b, int d){

	int cnt=1;
	check[a][b][d]=1;
	int na=a+dir[d][0],nb=b+dir[d][1];
	
	if(in[a][b]==in[na][nb])
		cnt+=dfs(na,nb,d);
	
	return cnt;
}
int main(){
	int flag=1;
	for(int i=1;i<=19;i++){
		for(int j=1;j<=19;j++){
			cin>>in[i][j];
		}
	}	
	//cout<<"hi";
	
	for(int i=1;i<=19;i++){
		for(int j=1;j<=19;j++){
			if(in[j][i]==0)
				continue;
			for(int k=0;k<4;k++){
				if(check[j][i][k])
					continue;
				if(dfs(j,i,k)==5)
				{
					cout<<in[j][i]<<"\n"<<j<<" "<<i;
					flag=0;
				}		
			}
		}
	}
	if(flag){
		cout<<0;
	}
	
}
