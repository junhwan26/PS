#include<iostream>
using namespace std;
long long fac[4000001];
long long inv[4000001];
long long power(long long a,long long b){
    if(b==0)
        return 1LL;
    if(b%2==0)
        return power((a*a)%10007,b/2)%10007;
    else
        return a*power((a*a)%10007, b/2)%10007;
}
int main(){
    int N,K;
    cin>>N>>K;
    fac[0] = 1;
    for(int i=1;i<=N;i++)
        fac[i] = i*fac[i-1]%10007;
    cout<<(fac[N]%10007*power(fac[K],10005)%10007*power(fac[N-K], 10005))% 10007<<endl;
    //cout<<fac[N]<<" "<<power(fac[K],10005)<<" "<<power(fac[N-K], 10005);

}
