#include<iostream>
#include<string>

using namespace std;

int dp[1001][1001];


int main(){
    string A, B;
    cin>>A>>B;
    for(int i=0;i<A.length();i++){
        for(int j = 0;j<B.length(); j++){
            if(A[i] == B[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    
    cout<<dp[A.length()][B.length()];
    
}
