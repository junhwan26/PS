#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int q[100000];
int front=0,back=0;

void push(int x){
	q[back]=x;
	back++;	
}

void pop(){
	if(front==back){
		printf("-1\n");
	}
	else
	{
		printf("%d\n",q[front]);
		front++;
	}
}

void ffront(){
	if(front==back){
		printf("-1\n");
	}
	else{
		printf("%d\n",q[front]);
	}
}

void fback(){
	if(front==back){
		printf("-1\n");
	}
	else{
		printf("%d\n",q[back-1]);
	}
}
void empty(){
	if(back==front){
		printf("1\n");
	}
	else
		printf("0\n");
}
void size(){
	printf("%d\n",back-front);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="push"){
			int d;
			cin>>d;
			push(d);
		}
		if(s=="pop"){
			pop();
		}
		if(s=="empty"){
			empty();
		}
		if(s=="size"){
			size();
		}
		if(s=="front"){
			ffront();
		}
		if(s=="back"){
			fback();
		}
	}
}
