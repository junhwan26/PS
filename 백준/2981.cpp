#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v1;
vector<long long> anss;
long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        v1.push_back(tmp);
    }
    
    sort(v1.begin(), v1.end());
    long long ans= v1[1] - v1[0];
    for(int i=2;i<n;i++){
        ans = gcd(ans,v1[i]-v1[i-1]);
    }

    
    for(int i=2;i*i<=ans;i++)
        if(ans%i==0){
            anss.push_back(i);
            anss.push_back(ans/i);
        }
    anss.push_back(ans);
    sort(anss.begin(), anss.end());
    anss.erase(unique(anss.begin(), anss.end()), anss.end());
    
    sort(anss.begin(),anss.end());
    for(int i=0;i<anss.size();i++)
        cout<<anss[i]<<" ";
    
}
