#include<iostream>
#include<stack>
using namespace std;

stack<pair<long long, long long>> st;


int main(){
    long long N;
    cin>>N;
    long long ans = 0;
    for(long long i=0;i<N;i++){
        long long tmp;
        cin>>tmp;
        while(!st.empty() && st.top().first < tmp){
//            cout<<">>>"<<st.top().first<<" "<<tmp<<" "<<st.top().second<<endl;
            ans+=st.top().second;
            st.pop();
        }
        
        long long tmp2=0;
        if(!st.empty()){
            if(st.top().first==tmp){
                tmp2 = st.top().second;
//                cout<<">>>"<<st.top().first<<" "<<tmp<<" "<<tmp2<<endl;
                ans+=tmp2;
                st.pop();
                
            }
            if(!st.empty()){
//                cout<<">>>"<<st.top().first<<" "<<tmp<<" "<<1<<endl;
                ans+=1;
            }
        }
        
        st.push({tmp,tmp2+1});
    }
    cout<<ans;
}
