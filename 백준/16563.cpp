#include<iostream>
#include<vector>
#define MAX 5000000

using namespace std;
int minfactor[MAX + 1];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=2;i<=MAX;i++)
        minfactor[i] = i;
    
    for(int i=2;i*i<=MAX; i++){
        if(minfactor[i] != i)
            continue;
        for(int j=i;j*i<=MAX;j++){
            if(minfactor[j*i] == j*i)
                minfactor[j*i] = i;
        }
    }
    
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        while(tmp>1){
            cout<<minfactor[tmp]<<" ";
            tmp/=minfactor[tmp];
        }
        cout<<"\n";
    }
    
    
    
}
