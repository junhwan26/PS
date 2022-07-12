#include<iostream>
#include<stack>
using namespace std;
int cnt[1000001];
stack<int> st;
stack<int> tmp;
stack<int> ans;
int main(){
    int N;
    cin>>N;
    for(int i=0; i<N;i++){
        int tmp;
        cin>>tmp;
        cnt[tmp] ++;
        st.push(tmp);
    }
    while(!st.empty()){
        while(!tmp.empty() && cnt[tmp.top()] <= cnt[st.top()]){
            tmp.pop();
        }
        if(tmp.empty())
            ans.push(-1);
        else
            ans.push(tmp.top());
        tmp.push(st.top());
        st.pop();
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
        
}
