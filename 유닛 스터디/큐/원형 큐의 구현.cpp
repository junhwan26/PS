#include<stdio.h>
#include<iostream>
using namespace std; 
int f=0,r=0,cur=0;
int arr[100];

int main()
{
	int n,k,m,tmp,cnt=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
	if(s=="create")
	{
		cin>>k;
	}
	else if(s=="remove")
	{
		if(cnt==0)
			printf("underflow\n");
		else
		{
		arr[f++]=0;
		if(f>=k)
		f=0;
		cnt--;
		
		for(int j=0;j<k;j++)
		{
			printf("%d ",arr[j]);
		}
		printf("\n");
	}
		
	}
	else if(s=="insert")
	{
		cin>>tmp;
		
		if(cnt>=k)
		{
			printf("overflow\n");
		}
		else{
			
		if(cur<k)
		{
			arr[cur++]=tmp;
			cnt++;
		}
		else
		{
			cur-=k;
			arr[cur++]=tmp;
			cnt++;	
		}
		for(int j=0;j<k;j++)
		{
			printf("%d ",arr[j]);
		}
		printf("\n");
		
		
		}
		
		
	}
	}
}
