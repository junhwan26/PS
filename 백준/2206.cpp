#include<iostream>
#include<queue>
#include<string>

using namespace std;

typedef struct{
    int x;
    int y;
    int block;
} dot;

int map[1001][1001];
int check[1001][1001][2];
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
queue<dot> q;


int main(){
    int N,M,ans=0;;
    cin>>N>>M;
    
    for(int i=1;i<=N;i++){
        string tmp;
        cin>>tmp;
        for(int j=1;j<=tmp.length();j++)
            map[i][j]=tmp[j-1]-'0';
    }
    
    q.push({1,1,0});
    check[1][1][0]=1;
    int flag=1;
    while(!q.empty() && flag){
        int size =q.size();
        ans++;
        
        for(int i=0;i<size;i++){
            
            int x=q.front().x, y=q.front().y, block=q.front().block;
            q.pop();
            
            
            if(x==N && y==M){
                flag=0;
                break;
            }
            
            for(int i=0;i<4;i++){
                int dx = x+dir[i][0], dy = y+dir[i][1], dblock = block+map[dx][dy];
                
                if( dx<1 || dy<1 || dx>N || dy>M || dblock > 1 || check[dx][dy][dblock])
                    continue;
                
                q.push({dx,dy,dblock});
                check[dx][dy][dblock] = 1;
            }
            
        }
    }
    
    if(flag)
        cout<<"-1";
    else
        cout<<ans;
    
}
