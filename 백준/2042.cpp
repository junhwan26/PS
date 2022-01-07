#include<iostream>

using namespace std;

long long st[8000001];
long long arr[1000000];
long long make_st(long long node, long long start, long long end)
{
    if (start == end)
        return st[node] = arr[start];

    long long mid = (start + end) / 2;
    return st[node] = make_st(node * 2, start, mid) + make_st(node * 2 + 1, mid + 1, end);
 
}


long long sum(long long node, long long start, long long end, long long left, long long right)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node];
 
    long long mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}


void update_st(long long node, long long start, long long end, long long index, long long diff)
{
    if (index < start || index > end) return;
    st[node] = st[node] + diff;
 
    if (start != end)
    {
        long long Mid = (start + end) / 2;
        update_st(node * 2, start, Mid, index, diff);
        update_st(node * 2 + 1, Mid + 1, end, index, diff);
    }
}




int main(){
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
            update_st(1, 0, N-1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        }
        else{
            cout<<sum(1, 0, N-1, b-1, c-1)<<"\n";
        }
    }
}

