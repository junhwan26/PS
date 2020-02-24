#include<iostream>
#include<algorithm>
using namespace std;
int set[500];
int one[500];
int main(){
	int n,m;
	cin>>n>>m;
	int setmin=10000,onemin=10000;
	for(int i=0;i<m;i++){
		int set,one;
		cin>>set>>one;
		setmin=min(set,setmin);
		onemin=min(one,onemin);
	}
	//cout<<onemin<<" "<<setmin;
	int money=0;
	
	if(n>=6&&setmin>onemin*6)
		money=n*onemin;
	else{
		if(n%6*onemin>setmin)
			money=(n/6+1)*setmin;
		else
			money=n/6*setmin+n%6*onemin;
	}
	cout<<money; 
}
