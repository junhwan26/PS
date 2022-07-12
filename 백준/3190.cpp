#include<iostream>
#include<queue>
using namespace std;
deque<pair<int, int>> dq;
int map[101][101];

int t = 0, d = 0;
int dir[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

void change_d(int C){
    if(C=='D')
        d+=1;
    else
        d-=1;
    if(d==4)
        d-=4;
    if(d<0)
        d+=4;
    return;
}

//d
// 오른쪽 0
// 아래쪽 1
// 왼쪽 2
// 위쪽 3
int main(){
    int N,K,L;
    cin>>N>>K;
    
    for(int i=0; i<K; i++){
        int a,b;
        cin>>a>>b;
        map[a][b] = 1;
    }
    
    dq.push_back({1,1});
    cin>>L;
    for(int i=0; i<L;i++){
        int a;
        char b;
        cin>>a>>b;
        while(t<a){
            t++;
            int nx = dq.front().first + dir[d][0], ny = dq.front().second + dir[d][1];
            //cout<<t<<" "<<d<<" "<<nx<<" "<<ny<<endl;
            if(nx<=0 || ny <= 0 || nx>N || ny> N){
                cout<<t;
                return 0;
            }
            //몸과 부딛히나 확인
            unsigned long size = dq.size();
            while(size--){
                int tmpx = dq.front().first, tmpy = dq.front().second;
                dq.pop_front();
                if(nx == tmpx && ny == tmpy){
                    cout<<t;
                    return 0;
                }
                dq.push_back({tmpx, tmpy});
            }
            
            dq.push_front({nx, ny});
            if(!map[nx][ny])
                dq.pop_back();
            else
                map[nx][ny] = 0;
        }
        change_d(b);
    }
    while(1){
        t++;
        int nx = dq.front().first + dir[d][0], ny = dq.front().second + dir[d][1];
        //cout<<nx<<" "<<ny<<endl;
        if(nx<=0 || ny <= 0 || nx>N || ny> N){
            cout<<t;
            return 0;
        }
        //몸과 부딛히나 확인
        unsigned long size = dq.size();
        while(size--){
            int tmpx = dq.front().first, tmpy = dq.front().second;
            dq.pop_front();
            if(nx == tmpx && ny == tmpy){
                cout<<t;
                return 0;
            }
            dq.push_back({tmpx, tmpy});
        }
        
        dq.push_front({nx, ny});
        if(!map[nx][ny])
            dq.pop_back();
        else
            map[nx][ny] = 0;
    }
}
