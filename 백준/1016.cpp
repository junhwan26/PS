#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int check[1000001];

int main(){
    long long a,b,cnt=0;
    cin>>a>>b;
    
    for(long long j=2; j<=sqrt(b); j++){
        long long tmp = (a/(j*j))*(j*j);
        //cout<<j<<endl;
        while(tmp<=b){
            if(tmp<a){
                tmp+=j*j;
                continue;
            }
                
            check[tmp-a] = 1;
            tmp+=j*j;
        }
    }
    for(long long i=a;i<=b;i++){
        if(!check[i-a])
            cnt++;
    }
    cout<<cnt;
}
