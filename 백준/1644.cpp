#include<iostream>
#include<vector>

using namespace std;
vector<int> prime;
int check[4000001];
int sum[4000001];
int main(){
    int N;
    cin>>N;
    for(int i=2;i<=4000000;i++)
        if(!check[i]){
            prime.push_back(i);
            for(int j=i;j<=4000000; j+=i){
                check[j] = 1;
            }
        }
    
    int start=0, ans=0, end=0, sum=0;
    while(start<prime.size()){
       //cout<<sum<<endl;
        if(sum<N && end<prime.size()){
            //cout<<end<<endl;
            sum+=prime[end++];
            continue;
        }
        
        if(sum==N){
            ans++;
            //cout<<prime[start]<<" "<<prime[end]<<endl;
        }
        
        sum-=prime[start++];
    }
    cout<<ans;
}
