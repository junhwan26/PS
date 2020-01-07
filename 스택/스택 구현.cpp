#include<iostream>
#include<stdio.h>
#include<string>
int arr[100];
int TOP = 0;
using namespace std;

int main()
{
	int n, d, max, i;
	string s;
	cin >> n;

	for (i = 0; i < n; i++)
	{


		cin >> s;
		if (s == "pop")
		{
			//cout << "pop ÀÔ·ÂµÊ";
			if (TOP == 0)
				cout<<"underflow\n";
			else
			{
				arr[--TOP] = 0;
				for (int j = 0; j < max; j++)
				{
					printf("%d ", arr[j]);
				}
				printf("\n");
			}
		}
		if (s == "push")
		{
			///cout << "push ÀÔ·ÂµÊ";
			if (TOP >= max)
			{
				cin >> d;
				printf("overflow\n");
			}
			else
			{
				cin >> arr[TOP++];
				for (int j = 0; j < max; j++)
				{
					printf("%d ", arr[j]);
				}
				printf("\n");
			}

		}
		if (s == "double")
		{
			max *= 2;
			if (max > 100)
				max = 100;
			//cout << "double ÀÔ·ÂµÊ";
		}

		if (s == "create")
		{
			//cout << "create ÀÔ·ÂµÊ";
			cin >> max;
		}

	}
}
