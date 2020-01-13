#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
long long que[500000];
long long f=0,back=0;
int prime(long long a)
{
    long long i;
    if(a==1)
        return 0;
       
    for(i=2;i*i<=a; i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
    
}
void push(long long data)
{
	que[back++]=data;
	if(back>=1000000)
	back=0;
}
long long front()
{
	return que[f];
}

void pop()
{
	f++;
	if(f>=1000000)
	f=0;
}

int main()
{
    long long n,chk=1,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
		chk*=10;
    	//printf("%lld\n",chk); 
	}
	if(n==9||n==10)
	{
		printf("0");
		return 0;
	}
    long long tmp=chk/10;
    long long cnt = 0;
    push(2);push(3);push(5);push(7);
	while(1)
	{
		long long tmp1=front();
		if(tmp1>=tmp&&tmp1<chk)
		{
			while(back!=f)
			{
				printf("%lld\n",front());
				pop();
				cnt++;
			}
			printf("%d",cnt);
			break;
		}
		pop();
		for(i=1;i<10;i++)
		{
			long long t=tmp1*10+i;
			if(prime(t))
			{
				push(t);
				//printf("%d %d\n",tmp1,t);	
			}
		}
	}
}

