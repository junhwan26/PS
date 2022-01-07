#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> v;
int parent[100001];

int find(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void union_(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main(){
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    
    for(int i=0;i<100001;i++)
        parent[i] = i;
    
    sort(v.begin(),v.end());
    int ans = 0, max_=0;
    
    for(int i=0;i<v.size();i++){
        int a = v[i].second.first, b = v[i].second.second;
        if(find(parent[a]) != find(parent[b])){
            ans+=v[i].first;
            max_ = max(max_,v[i].first);
            union_(a,b);
        }
    }
    cout<<ans-max_;
}
