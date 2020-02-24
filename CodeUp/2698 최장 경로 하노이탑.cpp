#include<iostream>
#include<stdio.h>
using namespace std;

int cnt;

void f(int num,char from, char by,char to){
	if(num==0)
		return;
	f(num-1,from,by,to);
	printf("%d : %c->%c\n",num,from,by);
	f(num-1,to,by,from);
	printf("%d : %c->%c\n",num,by,to);
	f(num-1,from,by,to);
	cnt+=2;
	
		
}

int main(){
	int n;
	scanf("%d",&n);
	f(n,'A','B','C');
	printf("%d",cnt);
}
