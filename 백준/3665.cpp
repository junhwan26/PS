#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int graph[501][501];
int in[501];
int g[501];
int ans[501];


void init(){
    for(int j=0;j<501;j++){
        for(int i=0;i<501;i++)
            graph[i][j] = 0;
        g[j]=0;
    }
        
}

int main(){
    int T;
    cin>>T;
    while(T--){
        init();
        int N;
        cin>>N;
        for(int i=1;i<=N;i++)
            cin>>in[i];
        
        for(int i=1;i<=N-1;i++)
            for(int j=i+1;j<=N;j++){
                graph[in[i]][in[j]] = 1;
                g[in[j]]++;
            }
        
        
        int M;
        cin>>M;
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            if(graph[a][b]){
                graph[a][b]=0;
                g[b]--;
                graph[b][a]=1;
                g[a]++;
            }
            else{
                graph[b][a]=0;
                g[a]--;
                graph[a][b]=1;
                g[b]++;
            }
        }
        
        stack<int> st;
        vector<int> ans;
        
        for(int i=1;i<=N;i++){
            if(g[i]==0){
                st.push(i);
            }
        }
        
        int flag=1;
        while(!st.empty()){
            
            if(st.size()>1){
                flag=0;
                break;
            }
            
            int a =st.top();
            st.pop();
            ans.push_back(a);
            
            for(int i=1;i<=N;i++){
                if(graph[a][i] == 1){
                    g[i]--;
                    if(g[i]==0)
                        st.push(i);
                }
            }
            
        }
        
        if(flag){
            if(ans.size()==N)
                for(int i=0;i<N;i++)
                    cout<<ans[i]<<" ";
            else
                cout<<"IMPOSSIBLE";
        }
        else{
            cout<<"?";
        }
        cout<<"\n";
        
        
    }
}
