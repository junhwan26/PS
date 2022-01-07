#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

string map[25];
int check[25][25];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int ans[700];

stack<pair<int, int>> st;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>map[i];
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!check[i][j] && map[i][j] == '1'){
                cnt++;
                st.push(make_pair(i, j));
                check[i][j] = cnt;
                
                while(!st.empty()){
                    int a =st.top().first, b= st.top().second;
                    st.pop();
                    for(int k=0;k<4;k++){
                        int na = a+dir[k][0], nb = b+dir[k][1];
                        
                        if(na<0 || nb<0|| na>=N || nb>=N|| check[na][nb] || map[na][nb] != '1')
                            continue;
                        
                        st.push(make_pair(na, nb));
                        check[na][nb] = cnt;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            if(check[i][j])
                ans[check[i][j]]++;
            //cout<<check[i][j];
        }
            
        //cout<<endl;
    }
        
    
    cout<<cnt<<"\n";
    //for(int i=0; i<=cnt; i++)
    //    cout<<ans[i]<<" ";
    //cout<<endl;
    sort(ans,ans+cnt+1);
    for(int i=1; i<=cnt; i++)
        cout<<ans[i]<<"\n";
}

/*
5
00000
00000
00000
00000
00000
 
5
10000
01000
00100
00010
00001
*/
