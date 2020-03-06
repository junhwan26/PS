#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a, int b){
	return a>b?1:0;
}

int main(){
	int n,A,B,C;
	int in[100];
	
	cin>>n;
	cin>>A;
	cin>>B;
	cin>>C;
	
	int cost=A, cal=C;
	
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	
	sort(in,in+n,cmp);
	
	for(int i=0;i<n;i++){
		if((float)cal/cost<(float)(cal+in[i])/(cost+B)){
			cal+=in[i];
			cost+=B;
		}
	}
	
	cout<<cal/cost;
	
}
