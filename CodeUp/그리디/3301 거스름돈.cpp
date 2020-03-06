#include<iostream>
using namespace std;

int main(){
	int money[8]={10,50,100,500,1000,5000,10000,50000};
	
	int n,cnt=0;
	cin>>n;
	
	for(int i=7;i>=0;i--){
		cnt+=n/money[i];
		n%=money[i];
	}
	
	cout<<cnt;
	
}
