#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[32001];
priority_queue<int, vector<int>, greater<int>> q;
int g[32001];

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        g[b]++;
    }
    for(int i=1;i<=N;i++){
        if(g[i]==0){
            g[i] = -1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int a = q.top();
        q.pop();
        cout<<a<<" ";
        for(int i=0; i<graph[a].size();i++){
            g[graph[a][i]]--;
            if(g[graph[a][i]] == 0){
                q.push(graph[a][i]);
            }
        }
        
    }
   
    
    
    
    
}
