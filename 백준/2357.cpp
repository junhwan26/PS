#include<iostream>

using namespace std;

long long st[8000001][2];
long long arr[1000000];

long long make_st0(long long node, long long start, long long end){
    if (start == end){
        return st[node][0] = arr[start];
    }
    long long mid = (start + end) / 2;
    return st[node][0] = min(make_st0(node * 2, start, mid), make_st0(node * 2 + 1, mid + 1, end));
 
}

long long make_st1(long long node, long long start, long long end){
    if (start == end){
        return st[node][1] = arr[start];

    }
    long long mid = (start + end) / 2;
    return st[node][1] = max(make_st1(node * 2, start, mid), make_st1(node * 2 + 1, mid + 1, end));
 
}

long long find_min(long long node, long long start, long long end, long long left, long long right)
{
    if (left > end || right < start) return 9876543210;
    if (left <= start && end <= right) return st[node][0];
 
    long long mid = (start + end) / 2;
    return min(find_min(node * 2, start, mid, left, right),find_min(node * 2 + 1, mid + 1, end, left, right));
}

long long find_max(long long node, long long start, long long end, long long left, long long right)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node][1];
 
    long long mid = (start + end) / 2;
    return max(find_max(node * 2, start, mid, left, right),find_max(node * 2 + 1, mid + 1, end, left, right));
}





int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,M;
    cin>>N>>M;
    for(long long i=0;i<N;i++){
        cin>>arr[i];
    }
    make_st0(1, 0, N-1);
    make_st1(1, 0, N-1);
    for(long long i=0;i<M;i++){
        long long a,b;
        cin>>a>>b;
        cout<<find_min(1, 0, N-1, a-1, b-1)<<" "<<find_max(1, 0, N-1, a-1, b-1)<<"\n";
    }
}

