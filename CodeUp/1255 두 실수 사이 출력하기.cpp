#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	float a,b;
	scanf("%f %f",&a,&b);
	//cout<<a<<" "<<b;

	for(float i=a;i<=b+0.001;i+=0.01){
		printf("%.2f ",i);
	}
}
