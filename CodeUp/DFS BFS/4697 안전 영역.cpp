#include<iostream>
using namespace std;
int in[100][100];
int check[100][100];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n;

void fill(int a, int b){
	check[a][b]=1;
	for(int i=0;i<4;i++){
		int na=a+dir[i][0], nb=b+dir[i][1];
		
		if(!in[na][nb]||check[na][nb]||na>=n||nb>=n||nb<0||na<0)
			continue;
		
		fill(na,nb);
	}	
}


int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>in[i][j];
		}
	}
	
	int ans=0;

	for(int h=1; h<=100; h++){
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(in[i][j]<=h)
					in[i][j]=0;
				check[i][j]=0;	
			}
		}

		int cnt=0;
		for(int i=0;i<n;i++){
			//cout<<n;
			for(int j=0;j<n;j++){
				if(check[i][j]||!in[i][j])
					continue;
				
				fill(i,j);
				cnt++;
			}
		}
		
		if(cnt==0)
			break;
		
		ans=max(cnt,ans);
	}	
	
	cout<<ans;
}
