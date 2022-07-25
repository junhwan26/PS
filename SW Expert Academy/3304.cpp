
#include<iostream>

using namespace std;

int dp[1001][1001];


int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string a, b;
        cin>>a>>b;
        for(int i=0;i<a.length();i++){
            for(int j=0;j<b.length();j++){
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                if(a[i] == b[j])
                    dp[i+1][j+1] = dp[i][j]+1;
            }
        }
        cout<<"#"<<test_case<<" "<<dp[a.length()][b.length()]<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
