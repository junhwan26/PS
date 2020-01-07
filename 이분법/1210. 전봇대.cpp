#include<stdio.h>
int n;
long long in[101111];

long long abs(long long a)
{
	return a > 0 ? a : -a;
}

long long dis(long long a)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += abs(in[i] - a * i);
	}
	return cnt;
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//	printf("i = %d : ",i);
		scanf("%lld", &in[i]);
	}
	int left = 1, right = in[n - 1];
	long long dl = dis(left), dr = dis(right) ,dm;
	while (right>left)
	{
		long long mid = (left + right) / 2;
		dm = dis(mid);
		printf("left=%d right= %d mid =%d dl =%d dr=%d dm=%d\n",left,right,mid ,dl,dr,dm);

		if (dl>=dm&&dr>=dm)
		{
			if(dis(mid+1)>dis(mid-1))
			{
				right=mid-1;
				dr=dm;
			}
			else
			{
				left = mid+1;
				dl=dm;
			}	
		}
		else if (dl>=dm&&dm>=dr)
		{
			left = mid;
			dl=dm;
		}
		else if(dr>=dm&&dm>=dl)
		{
			right=mid;
			dr=dm;
		}
		
		printf("[changed] left=%d right= %d\n",left,right);
	}
	if(dl<dr)
		printf("%d",dl);
	else
		printf("%d",dr);

}
