#include<iostream>
using namespace std;

int parent[500000];

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y){
    x = parent[x];
    y = parent[y];
    parent[x] = y;
}

int main(){
    int N,M, flag = 1;
    cin>>N>>M;
    for(int i=0;i<N;i++)
        parent[i] = i;
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        if(find(a) == find(b)){
            flag = 0;
            cout<<i;
            break;
        }
        _union(a,b);
    }
    if(flag)
        cout<<0;
}
