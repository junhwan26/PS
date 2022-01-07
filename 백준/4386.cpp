#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
vector<pair<double, pair<int, int>>> v;
int parent[100001];
double star[101][2];

int find(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void union_(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>star[i][0]>>star[i][1];
    }
    
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            double d =sqrt((star[i][0]-star[j][0])*(star[i][0]-star[j][0]) + (star[i][1]-star[j][1])*( star[i][1]-star[j][1]));            v.push_back(make_pair(d, make_pair(i, j)));
        }
    }
    
    for(int i=0;i<100001;i++)
        parent[i] = i;
    
    sort(v.begin(),v.end());
    double ans = 0;
    
    for(int i=0;i<v.size();i++){
        int a = v[i].second.first, b = v[i].second.second;
        if(find(parent[a]) != find(parent[b])){
            ans+=v[i].first;
            union_(a,b);
        }
    }
    printf("%.2lf",ans);
}
