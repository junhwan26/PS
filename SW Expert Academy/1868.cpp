
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

string map[301];
int check[301][301];
int visited[301][301];
int N;
int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
stack<pair<int, int>> st;

int ans;
void fill(int a, int b){
    visited[a][b] = ans;
    

    for(int i=0; i<8; i++){
        int na = a + dir[i][0], nb = b+dir[i][1];
        if(na<0 || nb <0 || na>=N || nb>=N || map[na][nb] == '*')
            continue;
        if(check[na][nb]){
                visited[na][nb] = ans;
        }
        
        else if(!visited[na][nb]){
            
            fill(na, nb);
        }
    }
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(check, 0, sizeof(check));
        memset(visited, 0, sizeof(visited));
        
        cin>>N;
        for(int i=0; i<N;i++)
                cin>>map[i];
        for(int i=0; i<N;i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j])
                    st.push({i,j});
                    while(!st.empty()){
                        int a = st.top().first, b = st.top().second;
                        st.pop();
                        visited[a][b] = 1;
                        for(int i=0; i<8; i++){
                            int na = a + dir[i][0], nb = b+dir[i][1];
                            if(na<0 || nb <0 || na>=N || nb>=N)
                                continue;
                            if(map[na][nb] == '*'){
                                check[a][b]++;
                                visited[na][nb] = 1;
                            }
                            else if(!visited[na][nb]){
                                visited[na][nb] = 1;
                                st.push({na, nb});
                            }
                        }
                        
                    }
            }
        }
        
        ans = 1;
        
        memset(visited, 0, sizeof(visited));
        
        for(int i=0; i<N;i++){
            for(int j=0; j<N; j++){
                if(!check[i][j] && !visited[i][j] && map[i][j] != '*'){
                    visited[i][j] = ans;
                    fill(i, j);
                    
                    ans++;
                }
            }
        }
        for(int i=0; i<N;i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j] && map[i][j] != '*'){
                    visited[i][j] = ans;

                    ans++;
                }
            }
        }
        
        
        cout<<"#"<<test_case<<" "<<ans-1<<endl;
            
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
