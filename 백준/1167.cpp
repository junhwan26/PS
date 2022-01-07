#include<iostream>
#include<vector>
using namespace std;

vector< vector< pair <int, int> > > v(100001);

int M, maxv;
int check[100001];
int len;
void start(int a){
    int flag=1;
    
    for(int i=0; i<v[a].size(); i++){
        int b=v[a][i].first, c=v[a][i].second;
        if(!check[b]){
            flag=0;
            len+=c;
            check[b]=1;
            start(b);
            check[b]=0;
            len-=c;
        }
    }
    
    if(flag && M<len){
        M = len;
        maxv = a;
        return;
    }
}

int main(){
    int N;
    cin>>N;
    
    while(N--){
        int a,b,c;
        cin>>a>>b;
        while(b!=-1){
            cin>>c;
            v[a].push_back(make_pair(b,c));
            cin>>b;
        }
    }
    check[1]=1;
    start(1);
    check[1]=0;
    
    check[maxv]=1;
    start(maxv);
    
    cout<<M;
    
}
