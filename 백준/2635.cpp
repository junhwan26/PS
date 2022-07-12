#include<iostream>
#include<vector>
using namespace std;
int ans;
vector<int> ansv;
int main(){
    int N;
    cin>>N;
    
    for(int j=0; j<= N; j++){
        vector<int> v;
        //cout<<j<<"----------j "<<endl;
        v.push_back(N);
        v.push_back(j);
        for(int i=2; ;i++){
            //cout<<v[i-2]<<" "<<v[i-1]<<endl;
            int tmp = v[i-2] - v[i-1];
            //cout<<"tmp "<<tmp<<endl;
            if(tmp < 0)
                break;
            v.push_back(tmp);
        }
        if(ans<v.size()){
            ansv = v;
            ans=v.size();
        }
            
    }
    cout<<ansv.size()<<endl;
    for(int i=0; i<ansv.size(); i++)
        cout<<ansv[i]<<" ";
}
