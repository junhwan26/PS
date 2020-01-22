#include<stdio.h>
long long max(long long a, long long b){
   return a>b?a:b;
}
int main(){
   long long n,k,m;
   
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
	scanf("%lld %lld %lld",&n,&k,&m);
   	long long left = 1LL, right = k;
   
   	while(left<=right){
      	long long mid = (left+right)/2;
      	long long G = n, Y=0, i = 0LL;
      	int flag=0;
      	//printf("%d %d\n",left,right);
      	while(G>0&&i<=k){
         	
			 //if(left==1&&right==499) printf("mid : %lld G : %lld Y : %lld => %lld\n",mid,n-G,G/mid,i);
         	
			 Y=G/mid;
         	
			 if(Y<=m){
            	
				flag=1;
            	G-=m*(k-i);
            	
				if(G<=0)
               		left = mid+1;
            	
				else
               		right= mid-1;
            break;
         }
         
         
    	i+=(G-Y*mid)/Y+1;
         
		G-=((G-Y*mid)/Y+1)*Y;   
      }
      if(flag) 
	  		continue;
	  		
      if(i<=k)
         left=mid+1;
      
	  else
         right = mid-1;
   }
   printf("%lld",right);
} 
