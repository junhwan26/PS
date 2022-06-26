#include<iostream>
using namespace std;
int in[17][17];
int ans;
int N;

void f(int a, int b, int d){
    if(a==N && b==N && in[a][b] == 0 ){
        ans++;
        return;
    }
    if(a>N || b > N || in[N][N])
        return;
    if(d == 0){
        if(!in[a][b+1])
            f(a,b+1,0);
        if(!in[a][b+1] && !in[a+1][b] && !in[a+1][b+1])
            f(a+1,b+1,2);
    }
    if(d == 1){
        if(!in[a+1][b])
            f(a+1,b,1);
        if(!in[a][b+1] && !in[a+1][b] && !in[a+1][b+1])
            f(a+1,b+1,2);
    }
    if(d == 2){
        if(!in[a][b+1])
            f(a,b+1,0);
        if(!in[a+1][b])
            f(a+1,b,1);
        if(!in[a][b+1] && !in[a+1][b] && !in[a+1][b+1])
            f(a+1,b+1,2);
        
    }
    
    

}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1; j<=N; j++)
            cin>>in[i][j];
    f(1,2,0);
    cout<<ans;
    
}
