#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 30000001
using namespace std;

vector<vector<pair<int, int>>> v(20010);

int d[20010];

int N,M,X;
void dijkstra(int x){
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(0,x));
    
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist > d[now])
            continue;
        
        for(int i =0; i<v[now].size(); i++){
            int cost = v[now][i].second+dist;
            int next = v[now][i].first;
            
            if(d[next]>cost){
                d[next] = cost;
                pq.push(make_pair(-cost,next));
            }
        }
    }
}

int main(){

    cin>>N>>M>>X;
    
    while(M--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
    }
    
    for(int i = 1; i <= N ; i++)
        for(int j = 1; j <= N ; j++){
            d[i]=INF;
            if(X==i)
                d[i]=0;
        }
            
    dijkstra(X);

    for(int i=1 ; i<=N ; i++){
        if(d[i]==INF)
            cout<<"INF"<<endl;
        else
            cout<<d[i]<<endl;
    }

}
