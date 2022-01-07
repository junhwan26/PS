#include<iostream>
#include<string>
#include<map>
using namespace std;

int parent[200002];
int sizes[200002];

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void _union(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        if(x>y)
            swap(x, y);
        parent[y] = x;
        sizes[x] += sizes[y];
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        map<string, int> m;
        int n = 1;
        for(int i=0;i<N;i++){
            string tmp1, tmp2;
            cin>>tmp1>>tmp2;
            
            if(m.count(tmp1) == 0){
                m[tmp1] = n++;
                sizes[m[tmp1]] = 1;
                parent[m[tmp1]] = m[tmp1];
            }
            
            if(m.count(tmp2) == 0){
                m[tmp2] = n++;
                sizes[m[tmp2]] = 1;
                parent[m[tmp2]] = m[tmp2];
            }
            
            _union(m[tmp1], m[tmp2]);
            cout<<max(sizes[find(m[tmp1])],sizes[find(m[tmp2])])<<"\n";
        }
    }
}
