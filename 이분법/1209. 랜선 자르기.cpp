#include<stdio.h>
int n,k;
int in[1000111];

int search(int left, int right)
{
	int mid=(left+right+1)/2;
	if(left==right)
		return left;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
	//	printf("cnt = %d mid = %d in[i] = %d\n",cnt,mid,in[i]);
		cnt+=(in[i]/mid);
	}
	printf("\nleft = %d  right = %d  mid = %d cnt = %d\n",left,right,mid,cnt);
	if(cnt>=k)
		return search(mid,right);
	else
		return search(left,mid-1);
		
}


int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	printf("%d",search(0,100000));
}
