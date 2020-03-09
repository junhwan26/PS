#include<iostream>
#include<String.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		char s[100];
		cin >> s;
		tmp=trlen(s);
		for (int j = 0; j < tmp; j++)
		{
			if (s[j] == '@')
			{
				cnt++;
				if (cnt == 2)
				{
					printf("No\n");
					continue
				}
			}
			if ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || s[j]==)
		}
	}

}
