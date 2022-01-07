#include<iostream>
#include<vector>
#define MAX 1000000

using namespace std;
long long sum[MAX + 1];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1;i<=MAX;i++){
        for(int j = i; j<=MAX; j+=i){
            sum[j]+=i;
        }
    }
    
    for(int i=1;i<=MAX;i++)
        //cout<<sum[i]<<" ";
        sum[i]+=sum[i-1];
    
    
    int N;
    cin>>N;
    while(N--){
        int tmp;
        cin>>tmp;
        cout<<sum[tmp]<<"\n";
    }
    
}
