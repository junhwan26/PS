#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
string dp[101][101];

string stringadd(string a, string b){
    //cout<<a<<" "<<b<<endl;
    string result="";
    int sum=0;
    while(!a.empty()||!b.empty()){
        
        if(!a.empty()){
            sum+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum+=b.back()-'0';
            b.pop_back();
        }
        //cout<<sum<<endl;;
        result.push_back(sum%10+'0');
        sum/=10;
    }
    if(sum>0)
        result.push_back(sum+'0');
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=100;i++){
        dp[i][0]="1";
        dp[i][i]="1";
        for(int j=1;j<i;j++){
            //cout<<"dp["<<i-1<<"]["<<j-1<<"]="<<dp[i-1][j-1]<<" dp["<<i-1<<"]["<<j<<"]="<<dp[i-1][j]<<endl;
            dp[i][j]=stringadd(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
     
    
}
