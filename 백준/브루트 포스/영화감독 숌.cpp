#include<iostream>
using namespace std;
int count6(int i){
	int cnt=0,flag=0;
	while(i>1){
		if(i%10==6){
			if(!flag)
				flag=1;
			cnt++;
		}
		else if(flag){
			if(cnt>=3)
				return cnt;
			flag=0;
			cnt=0;
		}
			
		i/=10;
	}
	return cnt;
}
int main(){
	int n,cnt=0,i=665;
	cin>>n;
	while(1){
		i++;
		if(count6(i)>=3)
			cnt++;
		if(cnt==n)
			break;
	}
	cout<<i;
}
