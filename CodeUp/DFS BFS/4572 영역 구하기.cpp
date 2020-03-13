#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int check[100][100];
vector<int> ans;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,k;
	
int fill(int a, int b){
	
	check[a][b]=1;
	int cnt=1;
	for(int i=0;i<4;i++){
		int na=a+dir[i][0], nb=b+dir[i][1];
		if(check[na][nb]||na<0||nb<0||na>=n||nb>=m)	
			continue;
		cnt+=fill(na,nb);
	}
	
	return cnt;
}

int main(){

	cin>>n>>m>>k;	
	
	
	for(int i=0;i<k;i++){
		int a1,b1,a2,b2;
		cin>>a1>>b1>>a2>>b2;
		
		for(int j=a1;j<a2;j++){
			for(int l=b1;l<b2;l++){
				check[l][j]=1;
			}
		}
	
	}
	


	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!check[i][j])
				ans.push_back(fill(i,j));
		}
	}
	
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}
