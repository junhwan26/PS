#include<iostream>
#include<vector>
using namespace std;
int map[12][12];
vector<pair<int, int>> v;
int dir[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};

int max_proc;
int ans;
int proc_cnt;
int line_cnt;
int N;
int check(int a, int b, int d){
    a+=dir[d][0];
    b+=dir[d][1];
    while(a<N && b<N && a>=0 && b>=0){
        if(map[a][b])
            return 0;
        a+=dir[d][0];
        b+=dir[d][1];
    }
    return 1;
}

void fill(int a, int b, int d){
    a+=dir[d][0];
    b+=dir[d][1];
    while(a<N && b<N && a>=0 && b>=0){
        
        map[a][b] = 1;
        line_cnt++;
        a+=dir[d][0];
        b+=dir[d][1];
    }
}
void unfill(int a, int b, int d){
    a+=dir[d][0];
    b+=dir[d][1];
    while(a<N && b<N && a>=0 && b>=0){
        map[a][b] = 0;
        line_cnt--;
        a+=dir[d][0];
        b+=dir[d][1];
        
    }
}

void dfs(int index){
    if(proc_cnt>max_proc){
        max_proc = proc_cnt;
        ans = line_cnt;
    }
    else if(proc_cnt == max_proc){
        ans = min(ans, line_cnt);
    }
    
    if(index==v.size())
        return;
    
    for(int i=0; i<4; i++){
        if(check(v[index].first, v[index].second,i)){
            fill(v[index].first, v[index].second,i);
            proc_cnt++;
            dfs(index+1);
            proc_cnt--;
            unfill(v[index].first, v[index].second,i);
        }
    }
    dfs(index+1);
    
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        cin>>N;
        v.clear();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
                if(map[i][j] && i!=0 && j!=0 && i!=N-1 && j!=N-1)
                    v.push_back({i,j});
            }
        }
        ans = 0;
        max_proc = 0;
        proc_cnt = 0;
        line_cnt = 0;
        dfs(0);
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
