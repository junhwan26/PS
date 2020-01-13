#include<stdio.h>
int n;
int arr[500000],copy[500000];

void merge(int left,int right)
{
	if(left>=right) 
		return;
	int mid = (left+right)/2;
	merge(left,mid);
	merge(mid+1,right);
	int low=left, high = mid+1, k = left;
	
	while(low<=mid||high<=right)
	{
		if(high>right||(low<=mid&&arr[low]<arr[high])) 
			copy[k++]=arr[low++];
		else 
			copy[k++]=arr[high++];
	}
	for(int i=left;i<=right;i++)
		arr[i]=copy[i];
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	merge(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

}
