

#include<iostream>

using namespace std;

long long arr[100001];
long long segtree[2 * 100001];
int n;

void update(long long i, long long x) {
    if(i&1)
        x=-x;
    segtree[i += n] = x;
    
    while (i >>= 1) {
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}

void init() {
    for (int i = 0; i < n; ++i) {
            segtree[i + n] = arr[i];
    }
    for (int i = n - 1; i != 0; --i) {
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}

long long query(long long l, long long r) {
    long long result = 0;
    for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
        if (l & 1) result += segtree[l++];
        if (r & 1) result += segtree[--r];
    }
    return result;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int q;
        scanf("%d %d",&n, &q);
        for(int i=0; i<n; i++){
            scanf("%lld", &arr[i]);
            if(i&1)
                arr[i] = -arr[i];
        }
            
        init();
        cout<<"#"<<test_case<<" ";
        
        while(q--){
            long long a,b,c;
            scanf("%lld %lld %lld",&a, &b, &c);
            if(a){
//                cout<<endl<<"---"<<searchmax(b, c)<<"-"<<searchmin(b, c)<<" ";
                if(b&1)
                    cout<<-query(b, c)<<" ";
                else
                    cout<<query(b, c)<<" ";
            
            }
            else
                update(b, c);
//            cout<<endl;
//            for(int i=0; i<n;i++)
//                cout<<arr[i]<<" ";
        }
        cout<<endl;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
             이 부분에 여러분의 알고리즘 구현이 들어갑니다.
         */
        /////////////////////////////////////////////////////////////////////////////////////////////


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
