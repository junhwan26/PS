#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ans;

int in[27][27];
int check[26][26];
int dir[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};


int fill(int a, int b){
	
	int cnt=1;
	check[a][b]=1;
	
	for(int i=0;i<4;i++){
		int na=a+dir[i][0], nb=b+dir[i][1];
		
		if( !in[na][nb] || check[na][nb])
			continue;
			
		cnt+=fill(na,nb);
	}
	
	return cnt;
}

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&in[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(in[i][j]==1&&!check[i][j]){
				ans.push_back(fill(i,j));
				//cout<<fill(i,j)<<"\n";
			}
		}
	}	

	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";	
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
}
