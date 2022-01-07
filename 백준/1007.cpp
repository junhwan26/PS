#include<iostream>
#include<stdio.h>
#include<cmath>

int in[21][2];
int visit[21];
long long xsum, ysum;
using namespace std;
int N;
double calc(){
    long long tmpx = 0, tmpy = 0;
    for(int i=1;i<=N;i++){
        if(visit[i]){
            tmpx+=2*in[i][0];
            tmpy+=2*in[i][1];
        }
    }
    long long x = xsum-tmpx;
    long long y = ysum-tmpy;
   // cout<<xsum<<" "<<tmpx<<endl;
    //cout<<x*x<<" "<<y<<endl;
    return sqrt(x*x+y*y);
}
double permute(int index, int cnt){
    double min_=987654321;
    if(cnt == N/2){
        //cout<<calc()<<endl;
        return calc();
    }
    for(int i=index+1;i<=N;i++){
        visit[i] = 1;
        min_ = min(min_,permute(i,cnt+1));
        visit[i] = 0;
    }
    return min_;
}
       
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        xsum=0;
        ysum=0;
        
        for(int i=1;i<=N;i++){
            visit[i] = 0;
            cin>>in[i][0]>>in[i][1];
            xsum+=in[i][0];
            ysum+=in[i][1];
        }
        printf("%.7lf\n",permute(0,0));

    }
}
