
#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>> q;
int map[101][101];
int visit[101][101];
int dir[4][2] = {{0,1}, {1,0}, {-1,0},{0,-1}};
int main(int argc, char** argv)
{
    int test_case;
    int T;
    int N;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {

          
        cin>>N;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin>>map[i][j];
                visit[i][j] = 0;
            }
                
        }
            
        int ans = 1;
        int h = 0;
        while(1){
            h++;
            int cnt = 0;
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(map[i][j]>h && visit[i][j]!=h){
                        cnt++;
                        visit[i][j] = h;
                        q.push({i,j});
                        while(!q.empty()){
                            int a = q.front().first, b = q.front().second;
                            q.pop();
                            for(int i =0; i<4; i++){
                                int na = a+dir[i][0], nb = b+dir[i][1];
                                if(na <= 0 || nb <= 0 || na > N || nb > N || visit[na][nb]==h || map[na][nb] <= h)
                                    continue;
                                q.push({na, nb});
                                visit[na][nb] = h;
                            }
                        }
                    }
                        
                }
            }
            ans = max(ans, cnt);
            if(cnt == 0)
                break;
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
        


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
