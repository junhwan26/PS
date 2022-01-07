#include<iostream>

using namespace std;

int parent[201];

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void _union(int x, int y){
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        parent[i] = i;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int tmp;
            cin>>tmp;
            if(tmp)
                _union(i,j);
        }
    }
    int f,flag=1;
    cin>>f;
    for(int i=1;i<M;i++){
        int tmp;
        cin>>tmp;
        if(find(f) != find(tmp))
            flag=0;
        
    }
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
