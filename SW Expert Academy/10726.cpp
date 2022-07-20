#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;
        cin>>N>>M;
        int tmp = 1;
        for(int i=0; i<N; i++){
            tmp*=2;
        }
        
        if((tmp-1 & M) == tmp-1)
            cout<<"#"<<test_case<<" ON"<<endl;
        else
            cout<<"#"<<test_case<<" OFF"<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
