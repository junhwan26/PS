#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cnt[50];

vector<pair<int, int>> v;

int f(int a, int b){
    if(a==1)
        return b;
    if(a==2)
        return 3*100-b;
    if(a==3)
        return 4*100-b;
    if(a==4)
        return 2*100 + b;
    return 0;
}

int main(){
    int N;
    cin>>N;
    for (int i =0; i<N/2; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back(make_pair( min(f(a,b), f(c,d)), max(f(a,b), f(c,d)))) ;
    }
    
    sort(v.begin(),v.end());
    int ans = 0, M=0;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if( v[i].first < v[j].first && v[i].second > v[j].first && v[i].second < v[j].second){
                cnt[i]++;
                cnt[j]++;
                ans++;
            }
        }
    }
    for(int i=0; i<v.size()-1;i++){
        //cout<<cnt[i]<<" ";
        M = max(M, cnt[i]);
    }
    //cout<<endl;
    cout<<ans<<endl<<M;
}
