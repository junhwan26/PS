#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int ans[2][50];
int in[100][50];
int main(){
    int N,M;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>ans[0][i];
        if(ans[0][i] + 2 > 4)
            ans[1][N-i-1] = (ans[0][i] + 2)%4;
        else
            ans[1][N-i-1] = (ans[0][i] + 2);
    }
    
    cin>>M;
    for(int i=0; i<M;i++){
        for(int j=0; j<N; j++){
            cin>>in[i][j];
        }
    }
    for(int i=0; i<M; i++){
        int j = 0, k = 0, tmp = 0;
        int check = 0;
        while(tmp<N){
            if(ans[0][j] != in[i][k]){
                tmp++;
                k=tmp;
                j=0;
            }
            else{
                j++;
                k++;
                k%=N;
            }
            if(j==N){
                check = 1;
                break;
            }
        }
        
        j = 0; k = 0; tmp = 0;
        while(tmp<N){
            if(ans[1][j] != in[i][k]){
                tmp++;
                k=tmp;
                j=0;
            }
            else{
                j++;
                k++;
                k%=N;
            }
            if(j==N){
                check=1;
                break;
            }
        }
        if(check)
            v.push_back(i);
            
        
    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size();i++){
        for(int j=0;j<N;j++){
            cout<<in[v[i]][j]<<" ";
        }
        cout<<endl;
    }
}
