#include<iostream>
int in[3500][6500];

using namespace std;
	int n;
void f(int a,int b, int len,int n){
	//printf("%d %d %d\n",a,b,len);
	if(len==5){
		in[a][b]=1;in[a][b+1]=1;in[a][b+2]=1;in[a][b+3]=1;in[a][b+4]=1;
		           in[a+1][b+1]=1;           in[a+1][b+3]=1;
		                        in[a+2][b+2]=1;
		return;
	}
	
	f(a,b,len/2,n/2);
	
	f(a	,b+len/2+1,len/2,n/2);
	
	f(a+n/2,b+len/4+1,len/2,n/2);
	
}

int main(){

	cin>>n;
	int m=n;
	int len=5*n/3+(n-1)/3;

	f(1,1,len,n);
	for(int i=m;i>=1;i--){
		for(int j=1;j<=len+1;j++){
			if(j==len+1&&i==1)
				break;
			if(in[i][j]==1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";
	}	
	
}
