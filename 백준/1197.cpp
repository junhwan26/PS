#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[10001];
vector<pair<int, pair<int, int>>> v;

int main(){
    int V,E;
    cin>>V>>E;
    
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    for(int i=1;i<=V;i++)
        parent[i] = i;
    
    sort(v.begin(),v.end());
    int ans=0;
    
    for(int i=0;i<v.size();i++){
        if(parent[v[i].second.first] != parent[v[i].second.second]){
            int tmp = parent[v[i].second.second];
            for(int j=1;j<=V;j++)
                if(parent[j] ==tmp)
                    parent[j] = parent[v[i].second.first];
                    
            ans+=v[i].first;
        }
        
    }
    cout<<ans;
    
}
