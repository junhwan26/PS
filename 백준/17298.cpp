#include<iostream>
#include<stack>
using namespace std;

int in[1000000];
int ans[1000000];
stack<pair<int, int>> st;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>in[i];
    }
    
    for(int i=0;i<N;i++){
        if(st.empty()){
            st.push(make_pair( in[i],i));
        }
        else{
            while(!st.empty()&&st.top().first<in[i]){
                ans[st.top().second] = in[i];
                st.pop();
            }
            st.push(make_pair(in[i],i));
        }
    }
    while(!st.empty()){
        ans[st.top().second] = -1;
        st.pop();
    }
    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";
    
}
