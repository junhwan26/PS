#include<iostream>
#include<string>
#include<queue>
using namespace std;
int x,y;
int R,C;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int day = 0;
queue<pair<int, int>> q1, q2, water1, water2;
string map[1500];
int visit[1500][1500];
int wvisit[1500][1500];
int melt[1500][1500];

void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        cin>>map[i];
        for(int j=0; j<C; j++){
            if(map[i][j] == 'L'){
                if(q1.empty()){
                    q1.push(make_pair(i, j));
                    visit[1][j] = 1;
                }
                   
    
                else{
                    x=i;
                    y=j;
                }
            }
            if(map[i][j]!='X'){
                water1.push(make_pair(i,j));
                wvisit[i][j] = 1;
            }
        }
    }
}

void print_map(){
    for(int i=0; i<R; i++){
        cout<<map[i]<<endl;
    }
    cout<<endl;
}

void print_melt(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
            cout<<melt[i][j];
        cout<<endl;
    }
}


int main(){
    input();
    while(1){
        
               
        while(!water1.empty()){
            int a, b;
            a = water1.front().first;
            b = water1.front().second;
            water1.pop();
            map[a][b] = '.';
            for(int i=0;i<4;i++){
                int da = a + dir[i][0];
                int db = b + dir[i][1];
                if( da < 0 || db < 0 || da >= R || db >= C || wvisit[da][db])
                    continue;
                if(map[da][db] == 'X')
                    water2.push(make_pair(da, db));
                    
                    
                else
                    water1.push(make_pair(da, db));
                wvisit[da][db] = 1;
            }
        }
        water1 = water2;
        while(!water2.empty())
            water2.pop();
//        cout<<day<<endl;
//        print_map();
        
        while(!q1.empty()){
            int a, b;
            a = q1.front().first;
            b = q1.front().second;
            q1.pop();

            for(int i=0;i<4;i++){
                int da = a + dir[i][0];
                int db = b + dir[i][1];
                if( da < 0 || db < 0 || da >= R || db >= C || visit[da][db])
                    continue;
                if(map[da][db] == 'X')
                    q2.push(make_pair(da, db));

                else
                    q1.push(make_pair(da, db));
                visit[da][db] = 1;
                    
            }
        }
        
        if(visit[x][y])
            break;
        
        q1 = q2;
        while(!q2.empty())
            q2.pop();

        day++;

    }
    
    cout<<day;
}

