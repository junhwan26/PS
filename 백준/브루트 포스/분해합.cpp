#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		int sum=i,tmp=i;
		
		for(int j=10000000;j>=1;j/=10){
			sum+=tmp/j;
			tmp%=j;
		}
		
		if(sum==n){
			cout<<i;
			return 0;
		}
	}
	cout<<"0";
}
