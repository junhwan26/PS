#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;
int dist[501];

int main(){
    int TC;
    cin>>TC;
    
    while(TC--){
        
        int N,M,W,flag=1;
        
        cin>>N>>M>>W;
        vector< vector<pair<int, int>>> v(501);

        for(int i=0;i<M;i++){
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b, c));
            v[b].push_back(make_pair(a, c));
        }
        
        for(int i=0;i<W;i++){
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(make_pair(b, -c));
        }
        
        
        for(int i=0;i<=N;i++){
            dist[i]=INF;
        }
        dist[N]=0;

        for(int i = 1; i <=N; i++){
            for(int j = 1 ; j<=N; j++){
                
                if(dist[j]==INF)
                    continue;
                
                for(int k=0; k < v[j].size(); k++){
                    int next = v[j][k].first;
                    int d = v[j][k].second;
                    
                    if(dist[next] > dist[j] + d){
                        if(i==N) flag=0;
                        dist[next] = dist[j] + d ;
                        
                    }
                }
            }
        }
        
        if(flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";
        
    
        
    }
    
}
