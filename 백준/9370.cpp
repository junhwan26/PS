#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dist[2001];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,t;
        cin>>n>>m>>t;
        
        for(int i=1; i<=n; i++){
            dist[i] = 987654321*2;
        }
        
        int s,g,h;
        cin>>s>>g>>h;
        
        
        vector<pair<int, int>> v[2001];
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if( (a==h&&b == g) || (a==g && b == h) ){
                v[a].push_back(make_pair(b, c*2-1));
                v[b].push_back(make_pair(a, c*2-1));
            }
            else{
                v[a].push_back(make_pair(b, c*2));
                v[b].push_back(make_pair(a, c*2));
            }
            
            
        }
        vector<int> ans;
        for(int i=0;i<t;i++){
            int tmp;
            cin>>tmp;
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        priority_queue<pair<int, int>> pq;
        
        pq.push(make_pair(0, s));
        dist[s] = 0;
        while(!pq.empty()){
            int d = -pq.top().first;
            int x = pq.top().second;
            pq.pop();
            
            for(int i=0;i<v[x].size();i++){
                if(dist[v[x][i].first] > d + v[x][i].second){
                    dist[v[x][i].first] = d + v[x][i].second;
                    pq.push(make_pair(-dist[v[x][i].first], v[x][i].first));
                }
            }
        }

        for(int i = 0; i<ans.size();i++){
            if(dist[ans[i]]%2)
                cout<<ans[i]<<" ";
        }
        cout<<"\n";
        
        
    }
}

