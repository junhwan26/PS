#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int K;
        string str;
        cin >> K >> str;
 
        vector<string> v;
        for (int i = 0; i < str.length(); i++)
            v.push_back(str.substr(i, str.length()));
 
        sort(v.begin(), v.end());
 
        cout << "#" << test_case << " " << v[K - 1] << endl;


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
