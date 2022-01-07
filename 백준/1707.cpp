#include<iostream>
#include<vector>
using namespace std;
int V, E;
int check[20001];
vector<int> graph[20001];

void dfs(int a, int c){
    check[a] = c;
    for(int i=0;i<graph[a].size();i++){
        if(!check[graph[a][i]]){
            dfs(graph[a][i],3-c);
        }
    }
}

int checkBG(){
    for(int i=1;i<=V;i++){
        for(int j=0;j<graph[i].size();j++){
            if(check[i]==check[graph[i][j]])
                return 0;
        }
    }
    return 1;
}

int main(){
    int K;
    cin>>K;
    while(K--){
        for(int i=0;i<20001;i++){
            graph[i].clear();
            check[i] = 0;
        }
        
        cin>>V>>E;
        for(int i=0;i<E;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=V;i++)
            if(!check[i])
                dfs(i,1);
        
        if(checkBG())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
