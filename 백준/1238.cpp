#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>> v(1001);
int d[1001][1001];

int N,M,X;
void dijkstra(int x){
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(0,x));
    
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist > d[x][now])
            continue;
        
        for(int i =0; i<v[now].size(); i++){
            int cost = v[now][i].second+dist;
            int next = v[now][i].first;
            
            if(d[x][next]>cost){
                d[x][next] = cost;
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
            d[i][j]=1000000;
            if(i==j)
                d[i][j]=0;
        }
            
    for(int i = 1; i <= N ; i++)
        dijkstra(i);
    
    int result = 0;
    for(int i = 1; i <= N; i++){
        result = max(result, d[X][i]+d[i][X]);
     //   cout<< d[X][i]<<" "<<d[i][X]<<endl;
    }
        
    
    cout<<result;
    
    
}
