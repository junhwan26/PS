#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int in[100001];

typedef struct dot{
	int p,c;
}dot;

int cmp(dot a, dot b){
	return a.p<b.p;
}

vector<dot> A;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int tmp1,tmp2;
		cin>>tmp1>>tmp2;
		dot a={tmp1,tmp2};
		A.push_back(a);
	}
	
	sort(A.begin(),A.end(),cmp);
	
	
	int ans=0;
	while(1){
		int flag=1;
		for(int i=1;i<=n;i++){
			if(A[i].c!=0){
				flag=0;
				for(int j=i;j<=n;j++){
					if(A[i].c!=0)
						A[i].c--;
					else{
						ans++;
						break;
					}
				}
			}
		}
		if(flag)
			break;	
	}
	cout<<ans;
}
