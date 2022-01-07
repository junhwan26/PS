#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

long long h[250000];
long long ans = 0;
map<int, int> h1, h2;

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        auto l = h1.lower_bound(tmp);
        auto r = h2.lower_bound(-tmp);
        int m = 0;
        if (l != h1.end())
            m = max(m, l->second);
        if (r != h2.end())
            m = max(m, r->second);
        h1[tmp] = h2[-tmp] = 1 + m;
        ans += 1 + m;
    }
    
    cout<<ans;
    
}
