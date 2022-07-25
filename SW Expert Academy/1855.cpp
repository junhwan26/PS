#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
#define MAX 25
using namespace std;

int parent[100001][MAX];
int depth[100001];
vector<int> v[100001];
stack<int> st;
queue<int> q;
int N;

long long LCA_D(int a, int b){
    int d =depth[a] - depth[b];
    int x,y;
    if(d>0){
        x = a;
        y = b;
    }
    else{
        y = a;
        x = b;
    }
    
    int i=0;
    while(d){
        if(d%2)
            x = parent[x][i++];
        d/=2;
    }
//    cout<<"a "<<a<<" b "<<b<<" D "<<d<<endl;;
//    cout<<"x "<<x<<" y "<<y<<endl;;
    if(x!=y){
        for(int i=MAX-1; i>=0; i--){
            if(parent[x][i] && parent[x][i] != parent[y][i]){
                x = parent[x][i];
                y = parent[y][i];
            }
        }
        x  = parent[x][0];
        
    }
    return depth[a] + depth[b] - depth[x]*2;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        for(int i=0; i<=N;i++)
            v[i].clear();
        memset(depth, 0, sizeof(depth));
        memset(parent, 0, sizeof(parent));
        for(int i=2; i<=N;i++){
            int tmp;
            cin>>tmp;
            v[tmp].push_back(i);
            parent[i][0] = tmp;
        }
        st.push(1);
        while(!st.empty()){
            int a = st.top();
            st.pop();
            for(int i=0; i<v[a].size(); i++){
                depth[v[a][i]] = depth[a]+1;
                st.push(v[a][i]);
            }
        }
//
//        for(int i=1; i<=N; i++)
//            cout<<depth[i]<<" ";
//        cout<<endl;
        
        for(int i=1; i<MAX; i++){
            for(int j=2; j<=N;j++){
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }

        long long ans = 0;
        q.push(1);
        while(!q.empty()){
            int a  = q.front();
            q.pop();
            
            
            for(int i=0; i<v[a].size(); i++){
                q.push(v[a][i]);
            }
            if(!q.empty())
                ans+=LCA_D(a, q.front());
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
             이 부분에 여러분의 알고리즘 구현이 들어갑니다.
         */
        /////////////////////////////////////////////////////////////////////////////////////////////


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
