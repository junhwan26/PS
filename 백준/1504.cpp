#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 200000000
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

    cin>>N>>M;
    
    while(M--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    
    int x,y;
    cin>>x>>y;
    
    for(int i = 1; i <= N ; i++)
        for(int j = 1; j <= N ; j++){
            d[i][j]=INF;
            if(i==j)
                d[i][j]=0;
        }
            
    dijkstra(1);
    dijkstra(x);
    dijkstra(y);
    dijkstra(N);
    
    /*
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    int result = 0;
    
    if(d[1][x]+d[x][y]+d[y][N]<d[1][y]+d[y][x]+d[x][N]){
        if(d[1][x]!=INF && d[x][y]!=INF && d[y][N]!=INF)
            result = d[1][x]+d[x][y]+d[y][N];
        else
            result = -1;
        
    }
    else{
        if(d[1][y]!=INF && d[y][x]!=INF && d[x][N]!=INF)
            result = d[1][y]+d[y][x]+d[x][N];
        else
            result = -1;
    }
    cout<<result;
    

}
