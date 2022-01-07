#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int in[9];
int visit[9];
vector<int> ans;

int N,M;

void func(int n){
    if(n==M){
        for(int i=0; i<M;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        return;
    }
    
    for(int i=1;i<=N;i++){
        if(!visit[i]){
            ans.push_back(in[i]);
            visit[i] = 1;
            func(n+1);
            visit[i] = 0;
            ans.pop_back();
        }
    }
    
    
    
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        cin>>in[i];
    
    sort(in+1,in+N+1);
    
    func(0);
    
}
