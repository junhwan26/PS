#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a,b;
int in[40];

void func(int i, int end, int sum, vector<int> &x){
    if(i == end){
        x.push_back(sum);
        return;
    }
    func(i+1,end,sum+in[i],x);
    func(i+1,end,sum,x);
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>in[i];
    
    func(0,n/2,0,a);
    func(n/2,n,0,b);
    
    sort(b.begin(),b.end());
    
    long long ans = 0;
    for(int i=0;i<a.size();i++){
        auto start = lower_bound(b.begin(), b.end(), s-a[i]);
        auto end = upper_bound(b.begin(), b.end(), s-a[i]);
        ans += end-start;
        
    }
    
    if(s==0)
        ans--;
    
    cout<<ans;
        
}
