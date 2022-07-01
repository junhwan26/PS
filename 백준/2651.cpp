#include<iostream>
#include<stack>

long long t[101];
long long dist[101];
long long dp[102];
long long backtracking[102];
using namespace std;
stack<long long> st;
int main(){
    int M;
    cin>>M;
    int N;
    cin>>N;

    dp[0]=0;
    for(int i=1; i<=N+1;i++){
        cin>>dist[i];
        dist[i]+=dist[i-1];
        dp[i]=2147483647;
    }
    
    for(int i=1; i<=N;i++){
        cin>>t[i];
    }
    
    for(int i=1; i<=N+1;i++){
        for(int j=0;j<i;j++){
            if(dist[i]-dist[j] <= M){
                if(dp[j] <= dp[i]){
                    dp[i] = dp[j];
                    backtracking[i] = j;
                }
            }
        }
        dp[i] += t[i];
//        for(int i =0; i<=N+1; i++)
//            cout<<dp[i] << " ";
//        cout<<endl;
    }
    long long tmp = backtracking[N+1];
    while(tmp!=0){
        st.push(tmp);
        tmp = backtracking[tmp];
    }
//    for(int i =0; i<=N+1; i++)
//        cout<<backtracking[i] << " ";
//    cout<<endl;
    cout<<dp[N+1]<<endl;
    cout<<st.size()<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
