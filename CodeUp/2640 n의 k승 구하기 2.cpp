#include<iostream>
using namespace std;
long long f(long long n,long long k){
//	cout<<n<<" "<<k<<"\n";
	if(k==1){
		//cout<<"ddd";
		return n;
	}	
		
	if(k%2==0)
		return f(n*n%1000000007,k/2)%1000000007;
	else
		return n*f(n*n%1000000007,k/2)%1000000007;
}

int main(){
	long long n,k;
	cin>>n;
	cin>>k;
//	cout<<n<<" "<<k<<"\n";
	cout<<f(n,k);
}
