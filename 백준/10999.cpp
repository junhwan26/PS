#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long
 
vector<LL> v, tree, lazy;
int n, m, k;
 
LL init(int node, int s, int e)
{
    if (s == e) return tree[node] = v[s];
    return tree[node] = init(2 * node, s, (s + e) / 2) +
        init(2 * node + 1, (s + e) / 2 + 1, e);
}
 
void update_lazy(int node, int s, int e)
{
    if (lazy[node] != 0) {
        tree[node] += (e - s + 1) * lazy[node];
 
        // leaf가 아니라면
        if (s != e) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
}
 
void update_range(int node, int l, int r, int s, int e, LL diff)
{
    update_lazy(node, s, e);
 
    if (r < s || e < l) return;
    
    if (l <= s && e <= r) {
        tree[node] += (e - s + 1) * diff;
 
        if (s != e) {
            lazy[2 * node] += diff;
            lazy[2 * node + 1] += diff;
        }
 
        return;
    }
 
    update_range(2 * node, l, r, s, (s + e) / 2, diff);
    update_range(2 * node + 1, l, r, (s + e) / 2 + 1, e, diff);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
LL sum(int node, int l, int r, int s, int e)
{
    update_lazy(node, s, e);
 
    if (r < s || e < l) return 0;
 
    if (l <= s && e <= r) return tree[node];
 
    return sum(2 * node, l, r, s, (s + e) / 2) +
        sum(2 * node + 1, l, r, (s + e) / 2 + 1, e);
}
 
int main()
{
    //freopen("C:\\Users\\park7\\Desktop\\buba.in.6", "r", stdin);
    cin.tie(0);
    scanf("%d %d %d", &n, &m, &k);
 
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
 
    v.assign(n, 0);
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);
 
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
 
    init(1, 0, n - 1);
 
    for (int i = 0; i < m + k; i++) {
        int a;
        scanf("%d", &a);
 
        if (a == 1) {
            int b, c;
            LL d;
            scanf("%d %d %lld", &b, &c, &d);
            update_range(1, b - 1, c - 1, 0, n - 1, d);
        }
        else {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(1, b - 1, c - 1, 0, n - 1));
        }
    }
 
    return 0;
}
