#include<iostream>
#include<vector>
#include<stack>


using namespace std;
stack<int> st;
vector<int> graph[32001];
vector<int> ans;
int g[32001];

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        g[b]++;
        graph[a].push_back(b);
    }
    
    while(ans.size()<N){
        if(st.empty()){
            for(int i=1;i<=N;i++){
                if(!g[i])
                    st.push(i);
            }
        }
        
        int a = st.top();
        ans.push_back(a);
        st.pop();
        for(int i=0;i<graph[a].size();i++){
            g[graph[a][i]]--;
            if(g[graph[a][i]] == 0)
                st.push(graph[a][i]);
        }
        
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
}
