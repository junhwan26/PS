#include<iostream>
#include<string>
using namespace std; 
string in[50];
string chess[8]={"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	//cout<<"d";
	int ans=64;
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			int cnt=0;
	//		cout<<i<<" "<<j;
			for(int k=i;k<i+8;k++){
				for(int l=j;l<j+8;l++){
					//cout<<in[k][l]<<" "<<chess[k-i][l-j]<<"\n";
					if(in[k][l]!=chess[k-i][l-j])
						cnt++;
				}
			}
			//cout<<i<<" "<<j<<" "<<cnt<<"\n";
			cnt=min(cnt,64-cnt);
			ans=min(ans,cnt);
		}
	}
			
	cout<<ans;
}

