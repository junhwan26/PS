#include<iostream>

using namespace std;

long long st[8000001];
long long arr[1000000];
long long make_st(long long node, long long start, long long end)
{
    if (start == end)
        return st[node] = arr[start]% 1000000007;

    long long mid = (start + end) / 2;
    return st[node] = (make_st(node * 2, start, mid) * make_st(node * 2 + 1, mid + 1, end))% 1000000007;
 
}


long long sum(long long node, long long start, long long end, long long left, long long right)
{
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return st[node];
 
    long long mid = (start + end) / 2;
    return (sum(node * 2, start, mid, left, right) * sum(node * 2 + 1, mid + 1, end, left, right))% 1000000007;
}


long long update_st(long long node, long long start, long long end, long long index, double val)
{
    if (index < start || index > end) return st[node];
    
    if(start == end)
        return st[node] = val;
 
   
        long long Mid = (start + end) / 2;
    return st[node]  = (update_st(node * 2, start, Mid, index,val) * update_st(node * 2 + 1, Mid + 1, end, index, val))% 1000000007;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,M,K;
    cin>>N>>M>>K;
    for(long long i=0;i<N;i++){
        cin>>arr[i];
    }
    make_st(1, 0, N-1);
    for(long long i=0;i<M+K;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update_st(1, 0, N-1, b-1, c);
        }
        else{
            cout<<sum(1, 0, N-1, b-1, c-1)<<"\n";
        }
    }
}


