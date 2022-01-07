#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int dp[101];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    int ans = 0;
    sort(v.begin(),v.end());
    for(int i=0; i<N;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    
    cout<<N-ans;
    
}
