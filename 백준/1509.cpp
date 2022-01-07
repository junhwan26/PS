#include<iostream>
#include<string>
using namespace std;
int dp[2501][2501];
int cnt[2501];
int main(){
    string str;
    cin>>str;
    str = "0"+str;
    int n = str.length()-1;
    for(int i=1;i<=n;i++)
        dp[i][i] = 1;
    
    for(int j=1;j<=n;j++){
        for(int i=1;i+j<=n;i++){
            if(str[i] == str[i+j] && (j==1 || dp[i+1][i+j-1]) )
                dp[i][i+j] = 1;
        }
    }
/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            //cout<<dp[i][j];
            if(dp[i][j])
                cout<<i<<" "<<j<<endl;
        cout<<endl;
    }
  */
    
    for(int i=1;i<=n;i++){
        cnt[i] = i;
        for(int j=1;j<=i;j++)
            if(dp[j][i]){
                cnt[i] = min(cnt[i], cnt[j-1]+dp[j][i]);
            }
        //cout<<cnt[i]<<" ";
    }
    cout<<cnt[n];
}

//12 3 45 678901 23456 7890 1 234 5678 90123 45
//BB C DD ECAECB DABAD DCEB A CCC BDCA ABDBA DD
