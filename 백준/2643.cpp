#include<iostream>
#include<vector>
#include<algorithm>

int dp[101];


using namespace std;
vector<pair<int, int>> v;

bool cmp(pair<int, int>a, pair<int, int>b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main(){
    int N;
    cin>>N;
    v.push_back(make_pair(0, 0));
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(max(a,b), min(a,b)));
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++)
            if(v[i].first>=v[j].first && v[i].second>=v[j].second)
                dp[i] = max(dp[i],dp[j]+1);
    }
    int ans = 0;
    for(int i=0; i<=N; i++){
        ans = max(ans,dp[i]);
        //cout<<dp[i]<<" ";
    }
    cout<<ans;
}
