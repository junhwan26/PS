#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> v;
int main(){
    int N;
    cin>>N;

    for(int i=0; i < N ; i++){
        long long x;
        cin>>x;

        if(v.empty() || v.back() < x)
            v.push_back(x);
        else{
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    
    cout<<v.size();
}


