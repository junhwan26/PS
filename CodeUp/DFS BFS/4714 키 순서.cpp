#include<iostream>
using namespace std;
int n,m;
int graph[501][501];
int check[501];

int dfs(int a, int d){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(graph[a][i]==d&&!check[i]){
			sum++;
			check[i]=1;
			sum+=dfs(i,d);
		}
	}
	return sum;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a][b]=1; // ¿€ 
		graph[b][a]=2; // ≈© 
	}
	
	int ans=0;

	for(int i=1;i<=n;i++){
		
		if(dfs(i,1)+dfs(i,2)==n-1){
			ans++;
		}
		
		for(int j=1;j<=n;j++)
			check[j]=0;	
	}
	cout<<ans;
}
