#include<stdio.h>
#include<map>
using namespace std;
map<long long,long long> m;

long long f(long long n){
	
	if(n==0)
		return 0;
	if(n<=2)
		return 1;
	if(n==3)
		return 2;
	if(n==4)
		return 3;
	if(m.find(n)!=m.end()){
		return m[n];
	}
		
	if(n%2==0){
		long long temp1=f(n/2);
		long long temp2=f(n/2-1);
		m[n]=((temp1)*(temp1+2*temp2))%1000000;
	

	}
	else{
		long long temp1=f(n/2+1);	
		long long temp2=f(n/2);
		m[n]=(temp1*temp1+temp2*temp2)%1000000;	
	}
	return m[n];
}
int main(){
	long long n;
	scanf("%lld",&n);
	printf("%lld",f(n));
}
