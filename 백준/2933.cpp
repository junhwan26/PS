#include<iostream>
#include<string>

using namespace std;
int R,C;
string map[101];
int stick[101];
int visit[101][101];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void search(int a, int b){
    visit[a][b] = 1;
    for(int i=0; i<4; i++){
        int na = a+dir[i][0], nb = b+dir[i][1];
        if(na<1 || nb <1 || na>R || nb >C || visit[na][nb] || map[na][nb] == '.')
            continue;
        search(na,nb);
    }
}

int main(){
    cin>>R>>C;
    for(int i=R; i>0; i--){
        string tmp;
        map[i] = "0";
        cin>>tmp;
        map[i]+=tmp;
    }
            
    

    
    int N;
    cin>>N;
    for(int T=1; T<=N; T++){
        int tmp;
        cin>>tmp;
//        cout<<map[tmp]<<endl;
        if(T%2==1){

            for(int j=1;j<=C;j++){
                if(map[tmp][j] == 'x'){
                    map[tmp][j] = '.';
                    break;
                }
            }
        }
        else{
            for(int j=C;j>0;j--){
                if(map[tmp][j] == 'x'){
                    map[tmp][j] = '.';
                    break;
                }
            }
            
        }
        
//        cout<<"막대기 던짐"<<endl;
//        for(int i=R; i>0; i--)
//            cout<<map[i]<<endl;
//        cout<<endl<<"visit"<<endl;
        
        for(int i=1;i<=R;i++)
            for(int j=1; j<=C; j++)
                visit[i][j] = 0;
        
        
        
        for(int i=1;i<=C;i++)
            if(map[1][i] == 'x')
                search(1,i);
        
        int cnt = 233;
        for(int j=1; j<=C; j++){
            for(int i=1; i<=R; i++){
                if(map[i][j] == 'x' && !visit[i][j]){
                    int k = i-1;
                    int tmp = 0;
                    while(k>0 && map[k][j]!='x'){
                        k--;
                        tmp++;
                    }
                    cnt = min(tmp, cnt);
                    break;
                
                }
            }
        }
//        cout<<"cnt"<<endl<<cnt<<endl;
        
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(map[i][j] == 'x' && !visit[i][j]){
                    map[i][j] = '.';
                    map[i-cnt][j] = 'x';
                }
            }
        }
        
        
//        for(int i=R;i>=1;i--){
//            for(int j=1; j<=C; j++)
//                cout<<visit[i][j];
//            cout<<endl;
//        }
//        cout<<endl<<"가라앉음"<<endl;
//
//        for(int i=R; i>0; i--)
//            cout<<map[i]<<endl;
//        cout<<endl<<endl;
        
    }
    
    
    
    for(int i=R; i>0; i--){
        for(int j=1; j<=C; j++)
            cout<<map[i][j];
        cout<<endl;
    }
}
