#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int t[1001];
int g[1001];
int ans[1001];
stack<pair<int, int>> st;
vector<int> graph[1001];

int main(){
    int d;
    cin>>d;
    while(d--){

        int N,K,T;
        cin>>N>>K;

        
        for(int i=1;i<=N;i++){
            cin>>t[i];
            ans[i] = 0;
            g[i] = 0;
            graph[i].clear();
        }
        
        
        for(int i=1;i<=K;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            g[b]++;
        }
        
        cin>>T;
        //cout<<d<<endl;
        
        for(int i=1;i<=N;i++){
            if(g[i]==0){
                st.push(make_pair(i, 0));
                g[i]=-1;
                ans[i] = 0;
            }
        }
        
        while(1){
            int a = st.top().first, b=st.top().second;
            //cout<<a<<endl;
            st.pop();
            
            if(a==T){
                cout<<b+t[a]<<"\n";
                break;
            }
            
            for(int i=0;i<graph[a].size();i++){
                g[graph[a][i]]--;
                ans[graph[a][i]] = max(ans[graph[a][i]],b + t[a]);
                if(g[graph[a][i]] == 0)
                    st.push(make_pair(graph[a][i], ans[graph[a][i]]));
            }
        }
        
        while(!st.empty())
            st.pop();
    }
}

/*
1
3 2
1 2 3
3 2
2 1
1
*/
