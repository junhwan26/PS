#include<iostream>
#include<queue>
using namespace std;

priority_queue<pair<int, int>> q;


int check[100001];

int main(){
    
    int N,K,ans=100001,cnt=0;
    cin>>N>>K;
    
    q.push(make_pair(0, N));
    
    while(!q.empty()){
        int x = q.top().second, time = -q.top().first;
        q.pop();
        check[x] = 1;
        if(time > ans )
            break;
        
        //cout<<x<<" "<<time<<endl;
        if(x == K){
            ans = time;
            cnt++;
        }
        
        if(x*2 < 100001 && !check[x*2])
            q.push(make_pair(-(time+1), x*2));
        
        if(x+1 < 100001 && !check[x+1])
            q.push(make_pair(-(time+1),x+1));
        
        if(x-1 < 100001 && !check[x-1])
            q.push(make_pair(-(time+1),x-1));
        
    }
    
    cout<<ans<<"\n"<<cnt;
}
