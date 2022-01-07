#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<pair<int,int>> q;


int check[100001];
int load[100001];
int main(){
    
    int N,K,time = 0;
    cin>>N>>K;

    
    q.push(make_pair(N, N));
    check[N] = 1;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0; i<size; i++){
            int now =q.front().first, before = q.front().second;
            q.pop();
            load[now] = before;
            
            if(now == K){
                cout<<time<<"\n";
                stack<int> ans;
                
                while(now != load[now]){
                    ans.push(now);
                    now = load[now];
                }
                ans.push(now);
                
                while(!ans.empty()){
                    int tmp;
                    tmp =ans.top();
                    ans.pop();
                    cout<<tmp<<" ";
                }
                return 0;
            }
 
            if(now-1 >= 0 && !check[now-1]){
                check[now-1] = 1;
                q.push(make_pair(now-1,now));
                
            }
            
            if(now+1 < 100001 && !check[now+1]){
                check[now+1] = 1;
                q.push(make_pair(now+1,now));
            }
            
            if(now*2 < 100001 && !check[now*2]){
                check[now*2] = 1;
                q.push( make_pair(now*2,now));
            }
            

            

            
            
        }
        time ++;

        
        //cout<<now<<" "<<time<<endl;
        
        

    }
}
