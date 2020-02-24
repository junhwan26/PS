#include<iostream>
using namespace std;
int in[5][1001];
int check[5][1001];
int ans[1001];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>in[j][i];
			check[j][in[j][i]]++;
		}
	}
	for(int j=0;j<5;j++){
		for(int i=0;i<n;i++){
			if(check[j][in[j][i]]==1)
				ans[i]+=in[j][i];
		}
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<"\n";
}
