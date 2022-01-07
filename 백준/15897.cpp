#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    long long ans=0;
    int i = N;
    while(i>0){
        //cout<<(N-1)/i+1<<" "<<((N-1)/((N-1)/i+1))<<"\n";
        ans+=((N-1)/i+1)*(i - (N-1)/((N-1)/i+1));
        i = (N-1)/((N-1)/i+1);
    }
    cout<<ans;
}
