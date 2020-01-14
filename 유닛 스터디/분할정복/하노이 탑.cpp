#include<stdio.h>
#include<stack>
using namespace std;

stack<int> A; //1
stack<int> B; //2
stack<int> C; //3


int move(int n, int from, int by, int to){
	if(n==1){
		printf("1 %c %c\n",from,to);
	}	
	else{
		move(n-1,from,to,by);
		printf("%d %c %c\n",n,from,to);
		move(n-1,by,from,to);
	}
}

int main(){
	int n;
	scanf("%d",&n);

	move(n,'A','B','C');
}
