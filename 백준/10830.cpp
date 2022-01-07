#include<iostream>
#include<vector>
using namespace std;


long long N,B;

vector<long long> prodeuct(vector<long long> a, vector<long long> b){
    vector<long long> result;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            long long tmp = 0;
            for(int k=0;k<N;k++){
                tmp+=a[i*N+k]*b[k*N+j];
            }
            result.push_back(tmp%1000);
        }
        
    }
    return result;

}


vector<long long> func(vector<long long> a, long long n){
    if(n==1){
        return a;
    }
    
    if(n%2==0){
        return func(prodeuct(a, a),n/2);
    }
    else{
        return prodeuct(a, func(prodeuct(a, a), n/2));
    }
}


int main(){
    cin>>N>>B;
    vector<long long> v;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
    }
    
    vector<long long> ans = func(v, B);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<ans[i*N+j]%1000<<" ";
        }
        cout<<"\n";
    }
    
    
    
}
