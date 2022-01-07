#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<pair<int, int>>> v(10001);
int len,m,maxi;
int check[10001];

void dfs(int a){
    
    int flag=1;
    for(int i=0;i<v[a].size();i++){
        if(!check[v[a][i].first]){
            //cout<<v[a][i].first<<" ";
            check[v[a][i].first]=1;
            len+=v[a][i].second;
            dfs(v[a][i].first);
            len-=v[a][i].second;
            check[v[a][i].first]=0;
            flag=0;
        }
        
    }
    if(flag){
        if(len>m){
            m=len;
            maxi=a;
            //cout<<"len = "<<len<<endl;
        }
    }
        

}

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
        
    }
    check[1]=1;
    dfs(1);
    check[1]=0;
    len=0;
    m=0;
    check[maxi]=1;
    dfs(maxi);
    cout<<m;
   
}
