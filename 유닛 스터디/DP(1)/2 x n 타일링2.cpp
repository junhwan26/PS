#include<iostream>

int save[1001];
using namespace std;
int f(int n){
	if(n==1)
		return 1;
	if (n==2)
		return 3;
	if(!save[n])	
		save[n]=f(n-1)+f(n-2)*2;
	
	return save[n]%10007;
	
}

int main(){
	int n;
	cin>>n;
	cout<<f(n);
}
