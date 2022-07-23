#include<iostream>
#include<vector>

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
        int N,M,L;
        cin>>N>>M>>L;
        vector<int> v;
        while(N--){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        while(M--){
            char c;
            cin>>c;
            if(c=='I'){
                int a, b;
                cin>>a>>b;
                v.insert(v.begin()+a, b);
            }
            else if(c=='D'){
                int a;
                cin>>a;
                v.erase(v.begin()+a);
            }
            else if(c=='C'){
                int a,b;
                cin>>a>>b;
                v[a] = b;
            }
        }
        cout<<"#"<<test_case<<" ";
        if(L>=v.size()){
            cout<<"-1"<<endl;
        }
        else
            cout<<v[L]<<endl;

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

