#include<iostream>
using namespace std;
long long in[3000][4];
int parent[3000];
int c[3000];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y){
    x = find(x);
    y = find(y);
    parent[x] = y;

}

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
    long long tmp = x1*y2+x2*y3+x3*y1 - (y1*x2 + y2*x3 + y3 * x1);
    if(tmp>0)
        return 1;
    else if(tmp<0)
        return -1;
    else
        return 0;
}



int check(long long x1, long long y1,long long x2,long long y2,long long x3, long long y3,long long x4,long long y4){
    long long a1 = CCW(x1,y1,x2,y2,x3,y3), a2 = CCW(x1,y1,x2,y2,x4,y4);
    long long b1 = CCW(x3,y3,x4,y4,x1,y1), b2 = CCW(x3,y3,x4,y4,x2,y2);
    
    if( a1*a2 <= 0 && b1*b2 <= 0 ){
        if(a1*a2 == 0 && b1*b2 == 0){
            if(max(x1,x2) >= min(x3,x4) && min(x1,x2) <= max(x3,x4) && max(y1,y2) >= min(y3,y4) && min(y1,y2) <= max(y3,y4))
                return 1;
            else
                return 0;
            
        }
        else
            return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>in[i][0]>>in[i][1]>>in[i][2]>>in[i][3];
        parent[i] = i;
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            //cout<<i<<" "<<" "<<j<<" "<<check(in[i][0], in[i][1], in[i][2], in[i][3], in[j][0], in[j][1], in[j][2], in[j][3])<<"\n";
            if(check(in[i][0], in[i][1], in[i][2], in[i][3], in[j][0], in[j][1], in[j][2], in[j][3]))
                _union(i, j);
        }
    }
    
    
    for(int i=0;i<N;i++){
        c[find(i)]++;
    }
    
    int cnt = 0, ans = 0;
    for(int i=0;i<N;i++){
        if(c[i])
            cnt++;
            ans = max(ans, c[i]);
    }
    cout<<cnt<<endl<<ans;
}

