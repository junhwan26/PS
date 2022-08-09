

#include<iostream>

using namespace std;

int arr[100001];
int segtree_max[2 * 100001];
int segtree_min[2 * 100001];
int n;

void update(int i, int x) {
    arr[i] = x;
    segtree_max[i+n] = x;
    segtree_min[i+n] = x;
    i+=n;
    while (i >>= 1) {
        segtree_max[i] = max(segtree_max[i << 1],segtree_max[i << 1 | 1]);
        segtree_min[i] = min(segtree_min[i << 1],segtree_min[i << 1 | 1]);
    }
}

void init() {
    for (int i = 0; i < n; ++i) {
        segtree_max[i + n] = arr[i];
        segtree_min[i+n] = arr[i];
    }
    for (int i = n - 1; i != 0; --i) {
        segtree_max[i] = max(segtree_max[i << 1], segtree_max[i << 1 | 1]);
        segtree_min[i] = min(segtree_min[i << 1], segtree_min[i << 1 | 1]);
    }
}

int searchmax(int l, int r) {
    int result = 0;
    for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
        if (l & 1) result = max(result, segtree_max[l++]);
        if (r & 1) result = max(result, segtree_max[--r]);
    }
    return result;
}
int searchmin(int l, int r) {
    int result = 1000000001;
    for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
        if (l & 1) result = min(result, segtree_min[l++]);
        if (r & 1) result = min(result, segtree_min[--r]);
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
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        init();
        cout<<"#"<<test_case<<" ";
        
        while(q--){
            int a,b,c;
            scanf("%d %d %d",&a, &b, &c);
            if(a){
//                cout<<endl<<"---"<<searchmax(b, c)<<"-"<<searchmin(b, c)<<" ";
                cout<<searchmax(b, c)-searchmin(b, c)<<" ";
            
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
