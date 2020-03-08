#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

queue<int> q;
queue<int> ans;
vector<int> vec[201];

int ind[201];


int main(){

	int v,n;
	cin>>v>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		vec[a].push_back(b);
		ind[b]++;		
	}
	
	for(int i=1;i<=v;i++){
		if(ind[i]==0)
			q.push(i);
	}

	while(!q.empty()){
		int size=q.size();

		for(int i=0;i<size;i++){
			int tmp=q.front();
			ind[tmp]--;
			ans.push(tmp);
			q.pop();
			
			for(int i=0;i<vec[tmp].size();i++){
				ind[vec[tmp][i]]--;
			}
			
		}
		
		for(int i=1;i<=v;i++)
			if(ind[i]==0){
				q.push(i);
				break;9
			}
				
	}
	if(ans.size()!=v)
		cout<<"-1";
	else{
		while(!ans.empty()){
			cout<<ans.front()<<"\n";
			ans.pop();
		}
	}
	
}
