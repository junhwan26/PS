#include<string>
#include<iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
string ss;
int cnt;
int size;
int A[4000010];
void manachers(string S, int N)
{
    int r = 0, p = 0;
    for (int i = 0; i < N; i++)
    {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
 
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1]&&A[i]<size)
            A[i]++;
 
        if (r < i + A[i])
        {
            r = i + A[i];
            p = i;
        }
    }
}

int main()
{
	int flag=0;
	cin >> ss;
	
	size=ss.size();
	
		
	string tmp=ss;
	for(int i=0;i<size-1;i++)
	{
		tmp+=ss[i];
	}

	int len = tmp.size();
 	string str;
    for (int i = 0; i < len; i++)
    {
        str += '#';
        str += tmp[i];
    }
    str += '#';

	//cout<<str<<endl;
	manachers(str, str.size());
	len = str.size();
	if(size%2==0)
	{
		for(int i=0;i<len;i++)
		{
		//	cout<<A[i]<<" ";
			if(A[i]==size&&str[i]=='#')
				cnt++;
		}
	}
	else
	{
		for(int i=0;i<len;i++)
		{
		//	cout<<A[i]<<" ";
			if(A[i]==size&&str[i]!='#')
				cnt++;
		}
	}

	cout<<cnt;
}
