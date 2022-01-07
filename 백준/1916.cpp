#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 20000000000
using namespace std;

vector<vector<pair<long long, long long>>> v(10001);

long long d[20010];

long long N,M,X;
void dijkstra(long long x){
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(0,x));
    d[x]=0;
    while(!pq.empty()){
        long long dist = -pq.top().first;
        long long now = pq.top().second;
        pq.pop();
        
        if(dist > d[now])
            continue;
        
        for(long long i =0; i<v[now].size(); i++){
            long long cost = v[now][i].second+dist;
            long long next = v[now][i].first;
            
            if(d[next]>cost){
                d[next] = cost;
                pq.push(make_pair(-cost,next));
            }
        }
    }
}

int main(){

    cin>>N>>M;
    
    while(M--){
        long long a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
    }
    
    for(long long i = 1; i <= N ; i++)
        for(long long j = 1; j <= N ; j++)
            d[i]=INF;
        
    long long x,y;
    cin>>x>>y;
    dijkstra(x);

    cout<<d[y];

}
