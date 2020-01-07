#include<stdio.h>
int in[1000011];
int m;
int search(int left, int right)
{
//	printf("left = %d right = %d\n",left, right);
	if(left==right)
		return right+1;
	int mid=(left+right)/2;
	if(in[mid]>m)
	{
		search(left,mid);
	}
	else
	{
		search(mid+1,right);
	}
	
}	
// 1 3 5 7 9
int main()
{

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}

	scanf("%d",&m);
	if(in[n-1]<=m)
		printf("%d",n+1);
	else
	printf("%d",search(0, n-1));
}
