#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

stack<char> s;
char str[51];
int ans[51];
char arr[51];
int TOP = 0;

int empty()
{
	if (TOP == 0)
		return 1;
	return 0;

}

int top()
{
	return arr[TOP - 1];
}

void pop()
{
	TOP--;
	return;
}

void push(int a)
{
	arr[TOP++] = a;
	return;
}

int main()
{

	int i, n, tmp,  cnt = 1;

	scanf("%s", str);
	n = strlen(str);
	for (i = 0; str[i] != NULL; i++)
	{
		if (!empty() && str[top()] == '(' && str[i] == ')')
		{
			ans[top()] = cnt;
			ans[i] = cnt;
			cnt++;
			pop();

		}
		else
			push(i);
	}

	if (empty())
	{
		for (i = 0; i < n; i++)
		{
			printf("%d ", ans[i]);
		}
	}
	else printf("WRONG EXPRESSION");


}
