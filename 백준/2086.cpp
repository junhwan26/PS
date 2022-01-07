#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<long long> vectorproduct(vector<long long> v1, vector<long long> v2){
    vector<long long> result;
    result.push_back((v1[0] * v2[0] + v1[1] * v2[2])%1000000000);
    result.push_back((v1[0] * v2[1] + v1[1] * v2[3])%1000000000);
    result.push_back((v1[2] * v2[0] + v1[3] * v2[2])%1000000000);
    result.push_back((v1[2] * v2[1] + v1[3] * v2[3])%1000000000);
    return result;
}

vector<long long> func(vector<long long> v, long long n){
    if(n==1)
        return v;
    if(n==0){
        vector<long long> a;
        a.push_back(0);
        a.push_back(0);
        a.push_back(0);
        return a;
    }
    if(n%2){
        return vectorproduct(v, func(vectorproduct(v, v),n/2));
    }
    return func(vectorproduct(v, v),n/2);
}

int main(){
    long long a,b;
    cin>>a>>b;
    a+=1;
    b+=2;
    a %= 1500000000;
    
    b %= 1500000000;
    vector<long long> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    vector<long long> ans;
    
    cout<<((func(v, b)[2] - func(v, a)[2])+1000000000 )%1000000000;
    
}
