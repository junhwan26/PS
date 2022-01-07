#include<iostream>
#define INF 51
#include<algorithm>
#include<vector>
using namespace std;
int map[51][51];
vector<int> v;
int main(){
    int N;
    cin>>N;
    int a=0,b=0;
    while(a!=-1){
        map[a][b]=1;
        map[b][a]=1;
        cin>>a>>b;
    }
    for(int i=1; i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!map[i][j])
                map[i][j] = INF;
            
        }
        map[i][i] = 0;
    }
    
//    for(int i=1; i<=N;i++){
//        for(int j=1;j<=N;j++)
//            cout<<map[i][j]<<" ";
//        cout<<endl;
//    }
    
    for(int k=1;k<=N;k++){
        for(int i=1; i<=N;i++){
            for(int j=1;j<=N;j++){
                map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
            }
        }
    }
    int m = 50;
    for(int i=1; i<=N;i++){
        int M = 0;
        for(int j=1;j<=N;j++)
            M = max(M, map[i][j]);
        if(M == m){
            v.push_back(i);
        }
        else if(M<m){
            v.clear();
            v.push_back(i);
            m=M;
        }
    }
    
    sort(v.begin(), v.end());
    cout<<m<<" "<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
        
}
