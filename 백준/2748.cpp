#include<iostream>
using namespace std;
long long p[100];


int main(){
    long long n;
    cin>>n;
    p[1]=1;
    p[0]=0;
    
    for(int i=2;i<=n;i++){
    	p[i]=p[i-1]+p[i-2];	
	}
    cout<<p[n];
}
