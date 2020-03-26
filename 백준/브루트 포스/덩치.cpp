#include<iostream>
using namespace std; 
int in[200][2];
int r[200];
int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>in[i][0]>>in[i][1];
	
	for(int i=0;i<n;i++){
		int tmp=1;
		for(int j=0;j<n;j++){
			if(in[i][0]<in[j][0]&&in[i][1]<in[j][1])
				tmp++;	
		}
		r[i]=tmp;	
	}
	
	for(int i=0;i<n;i++){
		cout<<r[i]<<" ";
	}	
}
