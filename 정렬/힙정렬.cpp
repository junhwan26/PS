#include<stdio.h>

int n;
int arr[500000];

void quick(int start, int end)
{
	int tmp;
	int pivot = arr[(start + end) / 2], left = start, right = end;
	do
	{
		while (arr[left] < pivot)	left++;
		while (arr[right] > pivot)	right--;
		if (left <= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	} while (left <= right);

	if (start < right)
		quick(start, right);
	if (end > left)
		quick(left, end);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quick(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

}
