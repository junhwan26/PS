#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int stack[100000];
int top=0;

void push(int x){
	stack[top]=x;
	top++;
}

int isempty(){
	if(top==0)
		return 1;
	return 0;
}
void ftop(){
	if(isempty()==1)
		printf("-1\n");
	else
		printf("%d\n",stack[top-1]);
}

void pop(){
	if(isempty()==1)
		printf("-1\n");
	else
	{
		printf("%d\n",stack[top-1]);
		top--;
	}
}


void size(){
	printf("%d\n",top);
}

int main(){
	int n;
	scanf("%d",&n);
	string s;
	for(int i=0;i<n;i++){
		
		cin>>s;
		if(s=="push"){
			int d;
			cin>>d;
			push(d);
		}
		if(s=="top"){
			ftop();
		}
		if(s=="pop"){
			pop();
		}
		if(s=="size"){
			size();
		}
		if(s=="empty"){
			if(isempty()==1)
				printf("1\n");
			else
				printf("0\n");
		}
	}	
}
