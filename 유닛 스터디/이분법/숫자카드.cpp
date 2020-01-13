#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		v.push_back(tmp); 
	}	
	
		sort(v.begin(),v.end());
	scanf("%d",&m);
	
	for(int i=0;i<m;i++){
		
		int tmp;
		int left=0, right=n-1;
		scanf("%d",&tmp);
		while(left!=right){
			int mid=(left+right)/2;
			
			if(v[mid]>=tmp){
				right=mid;
			}	
			
			else{
				left=mid+1;
			}
		}
		
		if(v[left]==tmp)
			printf("1 ");
		else
			printf("0 ");
	
	}

		

}
