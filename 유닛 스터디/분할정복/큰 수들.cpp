#include<stdio.h>

long long in[100001];
long long P;
int i;

long long f(long long  a,long long  n){
	//printf("%d %d\n",a,n);
	a%=P;
	if(n==1){
		return a;
	}
	
	if(n%2==0)
		return f(a*a,n/2)%P;
	
	return (a*f(a*a,n/2))%P;
}

long long k( long long n, long long A,long long N){
	

	if(n==1)
		in[1]=A;
	else
		in[n]=f(A,n)%P;
	
	if(n==N)
		return in[n];
	//printf("%d %d %d %d\n",n,A,N,in[n]);
	return k(n+1,in[n],N);
}	


int main(){
	int T;
	scanf("%d",&T);
	
	for(i=0;i<T;i++){
		long long A,N;
		scanf("%lld %lld %lld",&A,&N,&P);
		printf("%lld\n",k(1,A%P,N));
	}
}
