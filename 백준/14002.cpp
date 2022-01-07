#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
int check[1000000];
int in[1000000];
using namespace std;

vector<long long> v;
int main(){
    int N;
    cin>>N;

    for(int i=0; i < N ; i++){
        long long x;
        cin>>x;
        in[i] = x;
        if(v.empty() || v.back() < x){
            v.push_back(x);
            check[i] = v.size()-1;
        }
        else{
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
            check[i] = it-v.begin();
        }
    }
    cout<<v.size()<<endl;
    int x = v.size()-1;
    stack<long long> ans;
    for(int i=N-1;i>=0;i--){
        if(check[i] == x){
            ans.push(in[i]);
            x--;
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}


