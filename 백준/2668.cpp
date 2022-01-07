#include<iostream>
#include<stack>
using namespace std;

int map[101];
int check[101];
int N;
int cnt;
int dfs(int i, int j){
    
    if(check[i])
        return 0;
    
    check[i] = 1;
    if(i == j || dfs(map[i],j)){
        cnt++;
        return 1;
    }
    
    check[i] = 0;
    return 0;
}


int main(){
    
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>map[i];
    for(int i=1; i<=N; i++){
        if(!check[i])
            dfs(map[i],i);
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=N;i++)
        if(check[i])
            cout<<i<<"\n";
    
}
