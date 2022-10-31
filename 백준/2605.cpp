#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        v.insert(v.begin()+i-1-tmp, i);
    }
    for(int i=0; i<N;i++)
        cout<<v[i]<<" ";
    
}
