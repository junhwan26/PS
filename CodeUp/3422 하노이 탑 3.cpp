#include<iostream>
using namespace std;

int main(){
	unsigned long long n;
	cin>>n;
	unsigned long long i=1;
	unsigned long long k=1;
	while(k<=n){
		k=k*2+1;
		i++;
	//	cout<<i<<" "<<k<<"\n";
	}
	
	while(1){
	//	cout<<n<<" "<<k<<" "<<i<<"\n";
		if(n>k/2+1){
			n=n-k/2-1;
			k=k/2;
		}
		else if(n==k/2+1){
			cout<<i;
			break;
		}	
		else{
			k/=2;
		}
		i--;
	}
	
}
