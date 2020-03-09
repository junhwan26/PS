#include<iostream>
using namespace std;

int com[101][101];
int check[101];

int ans=-1;
int v,e;

void dfs(int n){
	check[n]=1;
	ans++;
	for(int i=1;i<=v;i++){
		if(com[n][i]==1&&!check[i]){
			dfs(i);
		}
			
	}	
}
int main(){

	
	cin>>v>>e;

	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		com[a][b]=1;
		com[b][a]=1;
	}	
	
	int n;
	dfs(1);
	
	cout<<ans; 

}
