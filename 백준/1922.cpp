#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> v;
int parent[1001];

int main(){
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    
    for(int i=0;i<1001;i++)
        parent[i] = i;
    
    sort(v.begin(),v.end());
    int ans = 0;
    
    for(int i=0;i<v.size();i++){
        int a = v[i].second.first, b = v[i].second.second;
        if(parent[a] != parent[b]){
            ans+=v[i].first;
            int tmp = parent[b];
            for(int i=1;i<=N;i++)
                if(parent[i] == tmp)
                    parent[i] = parent[a];
        }
    }
    cout<<ans;
}
