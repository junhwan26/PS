#include<iostream>
#include<algorithm>
int dp1[1000], dp2[1000];
int in[1000];
using namespace std;

int main(){
    int N,ans=0;
    cin>>N;
    
    for(int i=0; i < N; i++)
        cin >> in[i];
    
    
    for(int i = 0; i < N;i++){
        dp1[i] = 1;
        for(int j = i-1; j>=0; j--){
            if(in[i] > in[j])
                dp1[i] = max(dp1[i],dp1[j] + 1);
        }
    }
    
    for(int i = N-1 ; i>=0; i--){
        dp2[i] = 1;
        for(int j=i+1; j<N; j++){
            if(in[i]>in[j])
                dp2[i] = max(dp2[i], dp2[j]+1);
        }
    }
    
    for(int i=0;i<N;i++)
        ans = max(ans, dp1[i]+dp2[i]);
    
    cout<<ans-1;
}
