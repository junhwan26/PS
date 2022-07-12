#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int N;

int main(){
    vector<int> v[2];
    cin>>N;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        v[0].push_back(tmp);
    }
    vector<pair<int, int>> ans;
    int cnt = 0;
    while(cnt < N){
        int i;
        int max_[2];
        
        if(v[0].empty() || v[1].empty()){
            if(v[0].empty()){
                i=1;
                max_[1] = *max_element(v[1].begin(), v[1].end());
            }
                
            else{
                i=0;
                max_[0] = *max_element(v[0].begin(), v[0].end());
            }
        }
        
        else{
            max_[0] = *max_element(v[0].begin(), v[0].end());
            max_[1] = *max_element(v[1].begin(), v[1].end());
            //cout<<"max "<<max_[0]<<" "<<max_[1]<<endl;
            if(max_[0] > max_[1]){
                i = 0;
            }
            else
                i = 1;
        }
        
        
        while(max_[i] != v[i].back()){
            v[(i+1)%2].push_back(v[i].back());
            v[i].pop_back();
            //cout<<"back = "<<v[i].back()<<endl;
            ans.push_back({i+1, (i+1)%2+1 });
        }
        v[i].pop_back();
        ans.push_back({i+1, 3 });
        cnt++;
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
}
