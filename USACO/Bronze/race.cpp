#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;


int main(){
	long long n,k,x;
	
	freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    
    
    
	scanf("%lld %lld",&n,&k);
	
	for(long long i=0;i<k;i++){
		
		scanf("%lld",&x);
		long long length=1LL;
		
		if(x*x+x>= n*2)
		{
			for(int j=1;;j++){
				if(j*(j+1)>=n*2){
					printf("%d\n",j);
					break;
				}
			}
		}
		else
		while(1)
		{
			if((length+x-1)%2==1)
			{
				long long k=(length+x-1)/2+1;
				if((k*k-x*(x-1)/2)>=n)
				{

					printf("%lld\n",length);
					break;	
				}			
			}
			else
			{
				 long long k=(length+x-1)/2;
				if((k*(k+1)-x*(x-1)/2>=n))
				{

					printf("%lld\n",length);
					break;	
				}	
			}
			length++;
		
		}
	}
	
}

