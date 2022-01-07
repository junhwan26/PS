#include<iostream>

using namespace std;

int parent[1000001];

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
    while(M--){
        int a,b,c;
        cin>>c>>a>>b;
        if(c==1){
            if(find(a) == find(b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
            
        }
        else if(c==0){
            _union(a,b);
        }
    }
}
