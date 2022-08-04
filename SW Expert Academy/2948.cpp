#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N,M;
        cin>>N>>M;
        vector<string> v1;
        unordered_map<string, int> m1;
        
        for(int i=0; i<N;i++){
            string tmp;
            cin>>tmp;
            m1[tmp];
           
        }
        int ans=0;
        for(int i=0; i<M;i++){
            string tmp;
            cin>>tmp;
            if(m1.find(tmp)!=m1.end())
                ans++;
        }

        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

