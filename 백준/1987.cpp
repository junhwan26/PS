#include<iostream>
#include<string>
using namespace std;
int map[20][20];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int check[26];
int ans;
int r,c;
void dfs(int x, int y,int cnt){
    check[map[x][y]] = 1;
    int flag = 1;
    for(int i=0;i<4;i++){
        int nx = x+dir[i][0], ny = y+dir[i][1];
        if(nx>=r || ny >=c || nx<0 || ny<0 || check[map[nx][ny]])
            continue;
        dfs(nx,ny,cnt+1);
        flag=0;
    }
    if(flag == 1)
        ans = max(ans, cnt);
    check[map[x][y]] = 0;
}
int main(){
    
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<c;j++)
            map[i][j] = tmp[j]-'A';
    }
    
    dfs(0,0,1);
        
    
    
    cout<<ans;
}
