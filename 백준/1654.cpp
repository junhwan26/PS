#include <iostream>
#include<string>
using namespace std;
long long lan[10000];
long long n,k;

long long func(long long len){
    long long sum=0;
    for(long long i=0;i<k;i++){
        sum+=lan[i]/len;
    }
    return sum;
}

int main(int argc, const char * argv[]){
    cin>>k>>n;
    long long left=1,right=1;
    for(long long i=0;i<k;i++){
        cin>>lan[i];
        if(right<lan[i])
            right=lan[i];
    }
    
    while(left<right){
        long long mid=(left+right+1)/2;
        if(func(mid)<n){
            right=mid-1;
        }
        if(func(mid)>=n){
            left=mid;
        }
    }
    cout<<left;
    
    
}
