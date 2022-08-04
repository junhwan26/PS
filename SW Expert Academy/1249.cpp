
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int check[100][100];
int back[100][100][2];
using namespace std;
typedef  pair<int, pair<int, int>> pi;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {

        int N;
        cin>>N;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        string map[100];
        memset(check, 0, sizeof(check));
        for(int i=0;i < N;i++){
            cin>>map[i];
        }
        pq.push({0,{0,0}});
        check[0][0] = 1;
        int ans = 0;
        while(!pq.empty()){
            int a = pq.top().second.first, b = pq.top().second.second;
            int cost = pq.top().first;
            cout<<a<<" "<<b<<" "<<cost<<endl;
            if(a == N-1 && b== N-1){
                ans = cost;
                break;
            }
                
            pq.pop();
            for(int i=0; i<4; i++){
                int na= a+dir[i][0], nb = b+dir[i][1];
                if(na<0 || nb<0 || na>=N || nb>=N || check[na][nb])
                    continue;
                pq.push({map[na][nb]-'0' +cost, {na,nb}});
                check[na][nb] = 1;
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
