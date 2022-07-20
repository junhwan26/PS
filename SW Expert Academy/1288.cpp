#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int ans=0;
        int N;
        cin>>N;
        int check[10];
        for(int i=0; i<10;i++)
            check[i] = 0;
        int cnt = 0;
        int i = 1;
        while(cnt<10){
            int tmp = N*i;
            while(tmp>0){
                if(!check[tmp%10]){
                    check[tmp%10] = 1;
                    cnt++;
                }
                tmp/=10;
            }
            i++;
        }
        cout<<"#"<<test_case<<" "<<N*(i-1)<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

