#include<iostream>

using namespace std;
int map[100][100];
int check[100];
int N,L;
void initcheck(){
    for(int i=0;i<N;i++)
        check[i]=0;
}

int main(){
    
    cin>>N>>L;
    
    for(int i=0;i<N;i++)
        for(int j=0; j<N; j++)
            cin>>map[i][j];
    int ans=0;
    for(int i=0;i<N;i++){
        initcheck();
        int flag=1;
        int now = map[i][0];
        for(int j=1;j<N;j++){
            int prev = now;
            now = map[i][j];
            
            if(prev < now){ // 높아졌을 때
                if(now-prev>1){
                    flag=0;
                    break;
                }
                for(int k=j-1;k>j-L-1;k--){
                    if(k<0 ||map[i][k]!=prev||check[k]){
                        flag=0;
                        break;
                    }
                }
            }
            
            else if(prev > now){ //낮아졌을때
                if(prev-now>1){
                    flag=0;
                    break;
                }
                for(int k=j;k<j+L;k++){
                    if(k>=N || map[i][k]!= now){
                        flag=0;
                        break;
                    }
                    for(int k=j;k<j+L;k++)
                        check[k]=1;
                }
                j+=L-1;
            }
            
            if(!flag)
                break;
            
        }
        ans+=flag;
        
    }
    
    
    for(int i=0;i<N;i++){
        initcheck();
        int flag=1;
        int now = map[0][i];
        for(int j=1;j<N;j++){
            
            int prev = now;
            now = map[j][i];
            
            //cout<<"j = "<< j << ", i = " << i <<", now = "<<now<<", prev = "<<prev<<endl;
            
            if(prev < now){ // 높아졌을 때
                if(now-prev>1){
                    flag=0;
                    break;
                }
                for(int k=j-1;k>j-L-1;k--){
                    if(k<0 ||map[k][i]!=prev || check[k]){
                        flag=0;
                        break;
                    }
                }
            }
            
            else if(prev > now){ //낮아졌을때
                if(prev-now>1){
                    flag=0;
                    break;
                }
                for(int k=j;k<j+L;k++){
                    if(k>=N || map[k][i]!= now){
                        flag=0;
                        break;
                    }
                }
                
                for(int k=j;k<j+L;k++)
                    check[k]=1;
                
                j+=(L-1);
            }
            
            if(!flag)
                break;
            
        }
       ans+=flag;
        
    }
    cout<<ans;
    
}
