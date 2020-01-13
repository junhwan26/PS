#include<iostream>
#include<stdio.h>
#include<deque>
using namespace std;


int arr[5000001];

deque<int> dq;
deque<int> dqmax;

void dqs()
{
	deque<int> dqs = dq;
	while (!dqs.empty())
	{
		printf("%d ", dqs.front());
		dqs.pop_front();
	}
	printf("\n");
}

void dqms()
{
	deque<int> dqms = dqmax;
	while (!dqms.empty())
	{
		printf("%d ", dqms.front());
		dqms.pop_front();
	}
	printf("\n");
}

int main()
{

	int n, l, i;
	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (dq.empty())	dq.push_back(arr[i]);
		else
		{
			while (!dq.empty() && arr[i] < dq.back())
			{
				dq.pop_back();
			}

			if (!dq.empty()&&i >= l && arr[i - l] == dq.front())
				dq.pop_front();
			dq.push_back(arr[i]);
		}
		if(i>=l-1)
		//printf("i= %d arr[%d] = %d front = %d back = %d\n", i, i, arr[i], dq.front(), dq.back());
		//dqs();
		printf("%d ",dq.front() );
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (dqmax.empty()) dqmax.push_back(arr[i]);
		else
		{
			while (!dqmax.empty() && dqmax.back() < arr[i])
			{
				dqmax.pop_back();
			}
			if (!dqmax.empty()&&i >= l && arr[i - l] == dqmax.front())
			{
				dqmax.pop_front();
			}

			dqmax.push_back(arr[i]);
		}
		if(i>=l-1)
		printf("%d ",dqmax.front() );
		//printf("i= %d arr[%d] = %d front = %d back = %d\n", i, i, arr[i], dqmax.front(), dqmax.back());
		//dqms();

	}

}
