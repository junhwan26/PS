#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        long long n;
        scanf("%lld",&n);
        long long tmp = sqrt(n*2);
        long long ans = -1;
        if(tmp*(tmp+1) == 2*n)
            ans=tmp;

        printf("#%d %lld\n",test_case, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
