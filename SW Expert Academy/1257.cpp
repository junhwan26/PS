#include<string>
#include<set>
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
 
        set<string> s;
        
        for (int i = 0; i < str.length(); i++)
            for (int j = i+1; j <= str.length(); j++){
                //cout<<i<<" "<<j<<" "<<str.substr(i, j-i)<<endl;
                s.insert(str.substr(i, j-i));
            }
                

        string ans;

        int i = 1;
        for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++, i++){
            if (i == K) {
                ans = *iter;
                break;
            }
            if(i>K){
                ans = "none";
                break;
            }
        }
        
        cout << "#" << test_case << " " << ans << endl;


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
