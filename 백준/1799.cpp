#include<iostream>
using namespace std;
int map[10][10];
int l[20];
int r[20];
int N;
int c[2];
void dfs(int a, int b, int color, int cnt){
   // cout<<color<<" "<<cnt<<endl;
    
    if(a>=N){
        b++;
        if(a%2==0)
            a=1;
        else
            a=0;
    }
    if(b>=N){
        c[color] = max(c[color],cnt);
        return;
    }
    
    if( map[a][b] && !l[a+b] && !r[a-b+N]){
        l[a+b] = 1;
        r[a-b+N] = 1;
        dfs(a+2,b,color,cnt+1);
        l[a+b] = 0;
        r[a-b+N] = 0;
    }
    dfs(a+2,b,color,cnt);
    
}

int main(){
    cin>>N;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];

    dfs(0,0,0,0);
    dfs(1,0,1,0);
    cout<<c[0]+c[1];
}
