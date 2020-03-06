#include<iostream>

using namespace std;

int in[101][31];

int main(){
	int n,m;
	cin>>n;
	cin>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char tmp;
			cin>>tmp;
			if(tmp=='X')
				in[i][j]=0;
			else
				in[i][j]=1;
		}
	}
	
	int start,end;
	cin>>start;
	cin>>end;
	
	int ans=-1;
	
	while(start<end){
		//cout<<start<<"\n";
		int index=0;
		for(int j=1;j<=m;j++){
			if(in[start][j]){
				for(int k=start+1;k<=end;k++){
					if(!in[k][j]){
						index=max(index,k-1);		
						break;
					}
					
					if(k==end){
						index=end;
					}
				}
			}
		}
		
		if(index==0){
			ans=-1;
			break;
		}
		start=index+1;
		ans++;
		
	}
	cout<<ans;
}
