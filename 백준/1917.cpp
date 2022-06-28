#include<iostream>
#include<vector>
int in[6][6];
int check[6][6];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int ck[7];
// right, down, left, up
using namespace std;

// 아랫면 : 1
// 오른쪽 : 2
// 아래쪽 : 3
// 위쪽 : 4
// 왼쪽 : 5
// 윗면 : 6

vector<int> move(vector<int> v, int direction){
    vector<int> tmp;
    tmp.push_back(0);
    //오른쪽
    if(direction == 0){
        tmp.push_back(v[2]);
        tmp.push_back(v[6]);
        tmp.push_back(v[3]);
        tmp.push_back(v[4]);
        tmp.push_back(v[1]);
        tmp.push_back(v[5]);
        
    }
    //왼쪽
    if(direction == 2){
        tmp.push_back(v[5]);
        tmp.push_back(v[1]);
        tmp.push_back(v[3]);
        tmp.push_back(v[4]);
        tmp.push_back(v[6]);
        tmp.push_back(v[2]);
    }
    
    //down
    if(direction == 1){
        tmp.push_back(v[3]);
        tmp.push_back(v[2]);
        tmp.push_back(v[6]);
        tmp.push_back(v[1]);
        tmp.push_back(v[5]);
        tmp.push_back(v[4]);
    }
    
    // 아랫면 : 1
    // 오른쪽 : 2
    // 아래쪽 : 3
    // 위쪽 : 4
    // 왼쪽 : 5
    // 윗면 : 6
    
    if(direction == 3){
        tmp.push_back(v[4]);
        tmp.push_back(v[2]);
        tmp.push_back(v[1]);
        tmp.push_back(v[6]);
        tmp.push_back(v[5]);
        tmp.push_back(v[3]);
    }
    
    return tmp;
}


void dfs(int x, int y, vector<int> v){
    check[x][y] = v[1];
    for(int i=0; i<4; i++){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx<0 || ny<0 || nx>5 || ny > 5 || check[nx][ny] || !in[nx][ny])
            continue;
        dfs(nx,ny,move(v,i));
    }
}


int main(){
    int T=3;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    while(T--){
        for(int i=0;i<6;i++){
            for(int j=0; j<6;j++){
                cin>>in[i][j];
                check[i][j] = 0;
            }
            ck[i] = 0;
        }
        
        for(int i=0;i<6;i++){
            for(int j=0; j<6;j++){
                if(in[i][j] && !check[i][j]){
                    dfs(i,j,v);
                }
            }
        }
        for(int i=0;i<6;i++){
            for(int j=0; j<6;j++){
                //cout<<check[i][j]<<" ";
                if(check[i][j] > 0)
                ck[check[i][j]-1]++;
            }
            //cout<<endl;
        }
        
        int flag = 0;
        for(int i=0;i<6;i++)
            if(ck[i] != 1)
                flag=1;
        if(flag)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
                
    }
}
