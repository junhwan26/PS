#include<iostream>
#include<algorithm>
using namespace std; 
int c[100001];
int f(int n){
	if(n==1)	
		return 3;
	if(n==2)
		return 7;
	if(n==3)	return 17;
	if(!c[n])
		c[n]=5*f(n-2)%9901+2*f(n-3)%9901;
	return c[n]%9901;
}
int main(){
	int n;
	cin>>n;
	cout<<f(n);
	
}
