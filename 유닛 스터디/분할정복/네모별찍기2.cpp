#include<stdio.h>
#include<iostream>
using namespace std;
int in[5000][5000];
void f(int a, int b, int n){
	
	if(n==1){
		in[a][b]=1;
		return;
	}
		
	for(int j=0;j<3;j++){
		for(int i=0;i<3;i++){
			if(i!=1||j!=1){
					f(a+n/3*i,b+n/3*j,n/3);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	f(1,1,n);
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(in[i][j]==1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";
	}
}
