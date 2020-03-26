#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001];
int check[1001];
int n, m;



void dfs(int v) {

	check[v] = 1;
  	printf("%d ", v);
  	
  	for(int i = 1; i <= n; i++) 
  		if (graph[v][i] && !check[i])
		  dfs(i);
}

void bfs(int v) {
  queue <int> q;

  q.push(v);
  check[v] = 1;
  
  while(!q.empty()) {
    int tmp = q.front();  q.pop();
    
	check[tmp] = 1;
    printf("%d ", tmp);
   
    
    for (int i = 1; i <= n; i++) {
      	if(graph[tmp][i] && !check[i]) {
	        q.push(i);
	        check[i] = 1;
      	}
    }
    
  }

}


int main() {
	int v;
  	cin>>n>>m>>v;
	
 	for (int i = 1; i <= m; i++) {
 	 	int a,b;
    	cin>>a>>b;
    	graph[a][b] = 1;
    	graph[b][a] = 1;
  	}

  	dfs(v);
 	cout<<"\n";

    for (int i = 0; i <= 1000; i++) 
  		check[i] = 0; 
  	
	bfs(v);
  	cout<<"\n";

}

