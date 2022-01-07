#include<iostream>
#include<vector>
using namespace std;

vector<int> v[100001];
int parent[100001];

void search(int n){
    for(int i=0;i<v[n].size();i++){
        if(!parent[v[n][i]]){
            parent[v[n][i]] = n;
            search(v[n][i]);
        }
    }
    
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    parent[1]=1;
    search(1);
    for(int i=2;i<=N;i++)
        cout<<parent[i]<<"\n";
    
}
