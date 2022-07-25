#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int N,M, A[3001], B[101];
int dp[3001][101][101][2];

// n : A[n]를 볼거야
// a : B에서 고른 개수
// b : B에서 버린 갯수
// pre : 이전 과자 선택 여부
int func(int n, int a, int b, int pre){
    if(dp[n][a][b][pre]!=-1)
        return dp[n][a][b][pre];
    
    if(n==N && a+b == M)
        return 0;
    
    int& tmp = dp[n][a][b][pre];
    tmp = 0;
    
    if(pre == 0){
        if(n<N){
            tmp = max(tmp, func(n+1, a, b, 1) + A[n]);
            tmp = max(tmp, func(n+1, a, b, 0));
        }
        if(a+b < M){
            tmp = max(tmp, func(n, a+1, b, 1) + B[a]);
            tmp = max(tmp, func(n, a, b+1, 0));
        }
    }
    else{
        if(n<N){
            tmp = max(tmp, func(n+1, a, b, 0));
        }
        if(a+b < M){
            tmp = max(tmp, func(n, a, b+1, 0));
        }
    }
    return tmp;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        for(int i=0;i<N; i++)
            cin>>A[i];
        cin>>M;
        for(int i=0; i<M; i++)
            cin>>B[i];
    
        sort(B, B+M, greater<int>());
        
        memset(dp, -1, sizeof(dp));
        cout<<"#"<<test_case<<" "<<func(0, 0, 0, 0)<<endl;



    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

