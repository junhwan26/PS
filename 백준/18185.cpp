#include<iostream>
int in[10000];
using namespace std;

int main(){
    int N;
    cin>>N;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>in[i];
    }
    for(int i=0;i<N;i++){
        while(in[i] >0){
            int n = 3;
            int cnt = 0;
            if(in[i+1] > in[i+2])
                n=2;
            for(int j=0;j<n&&j+i<N;j++){
                if(in[i+j]>0){
                    in[i+j]--;
                    cnt++;
                }
                else
                    break;
            }
            switch (cnt) {
                case 1:
                    ans+=3;
                    break;
                case 2:
                    ans+=5;
                    break;
                case 3:
                    ans+=7;
                    break;
            }
        }
    }
    cout<<ans;
    
}
