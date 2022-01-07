#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<long long> bag;
vector<pair<long long, long long>> v;
priority_queue<long long> pq;
int main(){
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    
    for(int i=0;i<K;i++){
        long long tmp;
        cin>>tmp;
        bag.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    sort(bag.begin(),bag.end());
    long long ans=0,j=0;
    
    for(int i=0;i<K;i++){
        //cout<<bag[i]<<endl;
        while(j<N&&v[j].first<=bag[i])
            pq.push(v[j++].second);
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
            
        }
    }
    cout<<ans;
}
