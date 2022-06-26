#include<iostream>
using namespace std;

char map[64][64];

void f(int a1, int a2, int b1, int b2){
    int sum = 0;
    for(int i=a1;i<=a2;i++){
        for(int j=b1;j<=b2;j++){
            sum+=(map[i][j]-'0');
        }
    }
   //cout<<(a2-a1+1)*(b2-b1+1)<<" "<<sum<<endl;
    
    if(sum==0 || sum==(a2-a1+1)*(b2-b1+1)){
        cout<<map[a1][b1];
        return;
    }
    
    cout<<"(";
    int m = (a1+a2)/2;
    int n = (b1+b2)/2;
    f(a1,m,b1,n);
    f(a1,m,n+1,b2);
    f(m+1,a2,b1,n);
    f(m+1,a2,n+1,b2);
    cout<<")";
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%s",map[i]);
    }
    f(0,N-1,0,N-1);
    
}
