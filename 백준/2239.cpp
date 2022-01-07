#include<iostream>
#include<string>
using namespace std;
int row[10][10], map[10][10], col[10][10], square[10][10];

void print(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void dfs(int cnt){
    int a = cnt/9;
    int b = cnt%9;
    
    if(cnt==81){
        print();
        exit(0);
        return;
    }
    
    if(!map[a][b])
        for(int i=1;i<=9;i++){
            if( row[a][i] || col[b][i] || square[(a / 3) * 3 + (b / 3)][i])
                continue;
            map[a][b] = i;
            row[a][i] = 1;
            col[b][i] = 1;
            square[(a / 3) * 3 + (b / 3)][i] = 1;
            
            dfs(cnt+1);
            
            row[a][i] = 0;
            col[b][i] = 0;
            square[(a / 3) * 3 + (b / 3)][i] = 0;
            map[a][b]=0;
        }
    else
        dfs(cnt+1);
    
}

int main(){
    for (int i = 0; i < 9; i++){
        string tmp;
        cin>>tmp;
        for (int j = 0; j < 9; j++){
            map[i][j] = tmp[j]-'0';
            if (map[i][j] != 0)
            {
                row[i][map[i][j]] = 1;
                col[j][map[i][j]] = 1;
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = 1;
            }
        }
    }
    dfs(0);
    
}
