#include<stdio.h>

long long f(long long  a,long long  n){
	//printf("%d %d\n",a,n);
	a%=10007;
	if(n==1){
		return a;
	}
	
	if(n%2==0)
		return f(a*a,n/2)%10007;
	
	return (a*f(a*a,n/2))%10007;
}

int main(){
	long long  a,n;
	scanf("%d %d",&a,&n);
	printf("%lld",f(a,n));
}
