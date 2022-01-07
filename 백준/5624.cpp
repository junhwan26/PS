#include<iostream>
using namespace std;

int dp[400001];
int in[5000];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>in[i];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(!dp[in[i]+in[j]+200000])
                dp[in[i]+in[j]+200000] = i+1;
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[in[i]-in[j]+200000] && dp[in[i]-in[j]+200000]<i+1){
                //cout<<in[i]-in[j]+200000<<" "<<in[i]<<" "<<in[j]<<endl;
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    
}
