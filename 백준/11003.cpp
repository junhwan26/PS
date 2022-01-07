#include<deque>
#include<iostream>
using namespace std;
int in[5000001];
deque<pair<int, int>> dq;
int main(){
    ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

    int N,L;
    cin>>N>>L;
    for(int i=1;i<=N;i++){
        cin>>in[i];
    }
    
    for(int i=1;i<=N;i++){
        int start = max(i-L+1,1), end = i;
        
        if(dq.empty())
            dq.push_back(make_pair(in[i], i));
        
        if(dq.front().first >= in[i])
            dq.push_front(make_pair(in[i], i));
        else{
            while(!dq.empty() && dq.back().first > in[i])
                dq.pop_back();
            dq.push_back(make_pair(in[i], i));
        }
        
        while(!(dq.front().second >= start && dq.front().second <= end))
            dq.pop_front();
        cout<<dq.front().first<<" ";
            
        
    }
    
}


