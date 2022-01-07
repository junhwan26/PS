#include<iostream>
#define INF 987654321
using namespace std;

int d[101][101];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            d[i][j] = INF;
            if(i==j)
                d[i][j] = 0;
        }
            
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b] = min(c,d[a][b]);
    }
    
    for(int k = 1; k<=n; k++){
        for(int start = 1; start <= n ; start++){
            for(int end = 1; end<=n; end++){
                d[start][end] = min(d[start][k]+d[k][end], d[start][end]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j] == INF)
                cout<<"0 ";
            else
                cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
    
}
