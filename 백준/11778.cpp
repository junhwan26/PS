#include<iostream>
#include<vector>

using namespace std;

vector<long long> vectorproduct(vector<long long> v1, vector<long long> v2){
    vector<long long> result;
    result.push_back((v1[0] * v2[0] + v1[1] * v2[2])%1000000007);
    result.push_back((v1[0] * v2[1] + v1[1] * v2[3])%1000000007);
    result.push_back((v1[2] * v2[0] + v1[3] * v2[2])%1000000007);
    result.push_back((v1[2] * v2[1] + v1[3] * v2[3])%1000000007);
    return result;
}
long long gcd(long long a, long long b){
    return b?gcd(b,a%b):a;
}

vector<long long> func(vector<long long> v, long long n){
    if(n==1)
        return v;
    if(n%2){
        return vectorproduct(v, func(vectorproduct(v, v),n/2));
    }
    return func(vectorproduct(v, v),n/2);
}

int main(){
    long long N;
    cin>>N;
    vector<long long> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    vector<long long> ans =func(v, N);
    cout<<(ans[0] * ans[1])%1000000007;
    
}
