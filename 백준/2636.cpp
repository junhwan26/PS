#include<iostream>
using namespace std;
int n,m;
int map[102][102];
int visit[102][102];
int dir[4][2] = {{0,1},{1,0}, {-1,0}, {0,-1}};

void dfs(int a, int b){
    for(int i=0; i<4;i++){
        int na = a+dir[i][0], nb = b+dir[i][1];
        if(map[na][nb]==3)
            map[a][b] = 2;
        if(na<=0 || nb <= 0 || na>n || nb>m || visit[na][nb] || map[na][nb]!=1)
            continue;
        visit[na][nb] = 1;
        dfs(na,nb);
        
    }
}

void dfs2(int a, int b){
    map[a][b] = 3;
    for(int i=0; i<4;i++){
        int na = a+dir[i][0], nb = b+dir[i][1];
        if(na<=0 || nb <= 0 || na>n || nb>m || map[na][nb] == 1 || map[na][nb] == 3 )
            continue;
        dfs2(na,nb);
        
    }
}


int main(){
    int ans = 0;
    cin>>n>>m;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m;j++)
            cin>>map[i][j];

    dfs2(1,1);
    

    int day = 0;
    while(1){
        
        
        int cnt = 0;
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                if(map[i][j] == 1)
                    cnt+=1;
            }
        }
        if(cnt==0)
            break;
        ans = cnt;
        
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                if(map[i][j] && !visit[i][j] ){
                    visit[i][j] = 1;
                    dfs(i,j);
                    
                }
                   
            }
        }
        
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                if(map[i][j]==2){
                    map[i][j] = 3;
                    dfs2(i,j);
                }
                    
                visit[i][j] = 0;
            }
        }
        
        day++;
//        for(int i=1; i<=n;i++){
//            for(int j=1; j<=m;j++){
//                if(map[i][j] == 3)
//                    cout<<0;
//                else
//                cout<<map[i][j];
//            }
//            cout<<endl;
//        }
//        cout<<endl<<endl;
    }
    cout<<day<<endl<<ans;
    
        
}
