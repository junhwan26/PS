#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long parent[200000];

long long find(long long x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void _union(long long x, long long y){
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main(){
    while(1)
    {
        long long n,m;
        
        vector<pair<long long, pair<long long, long long>>> v;
        cin>>n>>m;
        
        if(n==0 && m==0)
            break;
        
        long long sum = 0;
        for(long long i=0;i<m;i++){
            long long a,b,c;
            cin>>a>>b>>c;
            v.push_back(make_pair(c, make_pair(a, b)));
            sum+=c;
        }
        
        for(long long i=0;i<n;i++){
            parent[i] = i;
        }
        
        long long ans = 0;
        sort(v.begin(), v.end());
        
        for(long long i=0;i<v.size();i++){
            long long a = v[i].second.first, b = v[i].second.second;
            if(find(a) != find(b)){
                ans += v[i].first;
                _union(a,b);
            }
        }
        cout<<sum-ans<<"\n";
    }
}
