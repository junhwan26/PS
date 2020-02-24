#include<iostream>
#include<algorithm>
using namespace std;
int in[200000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>in[i];
	sort(in,in+n);
	
	int day=0;
	
	for(int i=0;i<n;i++){
		if(in[i]>day)
			day++;
	}

	cout<<day;
	
	}
