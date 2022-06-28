#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string in[750];
int dp[750][750][2];
// 왼오 왼아


int R,C;

void print_dp(){
    for(int i=0;i<R;i++){
        for(int j=0; j<C; j++){
            cout<<dp[i][j][0];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<R;i++){
        for(int j=0; j<C; j++){
            cout<<dp[i][j][1];
        }
        cout<<endl;
    }
}

void find(int a, int b){
    int i=0, j=0, cnt=0;
    while(1){
        if(a+i<0 || b+j<0 || a+i>=R || b+j >= C || in[a+i][b+j] == '0' )
            break;
        i++;
        j++;
        cnt++;
    }
    dp[a][b][0] = cnt;
    i=0;
    j=0;
    cnt=0;
    while(1){
        if(a+i<0 || b+j<0 || a+i>=R || b+j >= C || in[a+i][b+j] == '0')
            break;
        i++;
        j--;
        cnt++;
    }
    dp[a][b][1] = cnt;
    
}

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
            cin>>in[i];
    }

    for(int i=0;i<R;i++){
        for(int j=0; j<C; j++){
            find(i,j);
            
        }
    }
    
    
    int ans = 0;
    for(int i=0;i<R;i++){
        for(int j=0; j<C; j++){
            int tmp = min(dp[i][j][0], dp[i][j][1])-1;
            while(tmp>=0){
                if(dp[i+tmp][j+tmp][1] > tmp && dp[i+tmp][j-tmp][0] > tmp )
                    ans = max(ans, tmp+1);
                tmp--;
            }
            
            
        }
    }
    cout<<ans;

}
