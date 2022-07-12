#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
vector<int> sorted;
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        sorted.push_back(tmp);
    }
        
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()),sorted.end());
    
    for(int i=0;i<N;i++)
        cout<<lower_bound(sorted.begin(), sorted.end(), v[i])- sorted.begin()<<" ";
}
