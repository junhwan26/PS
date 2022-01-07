#include<iostream>

using namespace std;

long long st[8000001];
long long lazy[8000001];
long long arr[1000000];
long long make_st(long long node, long long start, long long end)
{
    if (start == end)
        return st[node] = arr[start];

    long long mid = (start + end) / 2;
    return st[node] = make_st(node * 2, start, mid) + make_st(node * 2 + 1, mid + 1, end);
 
}




void update_lazy(long long node, long long start, long long end)
{
    if(lazy[node] != 0){
        st[node] += (end-start+1) * lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

long long sum(long long node, long long start, long long end, long long left, long long right)
{
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node];
 
    long long mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update_st(long long node, long long start, long long end, long long left, long long right, long long diff)
{
    update_lazy(node, start, end);
    
    if (right < start || left > end) return;
    
    if (left <= start && end <= right) {
          st[node] += (end-start+1)*diff;
          if (start != end) {
              lazy[node*2] += diff;
              lazy[node*2+1] += diff;
          }
          return;
    }
    
    update_st(node*2, start, (start +end)/2, left,right, diff);
    update_st(node*2+1,(start +end)/2 +1, end, left,right, diff);
    st[node] = st[node*2] + st[node*2 +1];
    return;
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
            int tmp;
            cin>>tmp;
            update_st(1, 0, N-1, b-1,c-1, tmp);
            arr[b-1] = c;
        }
        else{
            cout<<sum(1, 0, N-1, b-1, c-1)<<"\n";
        }
    }
}


