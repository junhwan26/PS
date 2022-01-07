#include<iostream>
#include<vector>
using namespace std;

vector<int> truth;
int parent[51];
vector<vector <int>> party(50);

int find_parent(int x){
    if(x==parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}


void union_parent(int x, int y){
    x=find_parent(x);
    y=find_parent(y);
    parent[y]=x;
}


int main(){
    
    int N,M,T;
    cin>>N>>M>>T;
    
    for(int i=1;i<=N;i++)
        parent[i]=i;
    
    for(int i=0;i<T;i++){
        int tmp;
        cin>>tmp;
        truth.push_back(tmp);
    }
    
    for(int i=0;i<M;i++){
        int n,tmp,prev_tmp;
        cin>>n;
        cin>>tmp;
        party[i].push_back(tmp);
        
        for(int j=1;j<n;j++){
            prev_tmp=tmp;
            cin>>tmp;
            union_parent(prev_tmp,tmp);
            party[i].push_back(tmp);
        }
    }
    int result = 0;
    for(int i=0; i<M; i++){
        int flag=1;
        for(int j=0;j<party[i].size();j++){
            for(int k=0;k<truth.size();k++){
                if( find_parent(truth[k]) == find_parent(party[i][j])){
                    flag=0;
                }
            }
        }
        result+=flag;
    }
    cout<<result;
    
}
