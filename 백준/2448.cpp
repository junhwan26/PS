#include<iostream>
using namespace std;

int star[3100][6200];

void func(int a,int b,int len){
    if(len==3){
        star[a][b] = 1;
        star[a+1][b] = 1;
        //star[a+1][b+1] = 2;
        star[a+1][b+2]=1;
        for(int i=0;i<5;i++)
            star[a+2][b+i]=1;
        //star[a+2][b+5]=2;
        return;
    }
    func(a,b,len/2);
    func(a+len/2,b,len/2);
    func(a+len/2,b+len,len/2);
}


int main(){
    int N;
    cin>>N;
    func(0,0,N);
    for(int i=0;i<N;i++){
        int cnt=0;
        for(int j=N-1;j>i;j--){
            cout<<" ";
            cnt++;
        }
        for(int k=0;k<N*2;k++){
            if(cnt<=2*N-2){
                if(star[i][k])
                    cout<<"*";
                else
                    cout<<" ";
                cnt++;
            }
        
            
               
        }
        cout<<"\n";
    }
    return 0;
}

