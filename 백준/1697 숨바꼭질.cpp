#include<iostream>
#include<queue>
using namespace std;

int check[100001];
queue<int> q;

int main(){
	int a,b,ans=0;
	cin>>a>>b;
	q.push(a);
	check[a]=1;
	
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		if(tmp==b){
			cout<<check[tmp]-1;
			break;
		}
		if(tmp+1<=100000&&!check[tmp+1]){
			q.push(tmp+1);
			check[tmp+1]=check[tmp]+1;
		}
			
		if(tmp-1>=0&&!check[tmp-1]){
			q.push(tmp-1);
			check[tmp-1]=check[tmp]+1;
		}
			
		if(tmp*2<=100000&&!check[tmp*2]){
			q.push(tmp*2);
			check[tmp*2]=check[tmp]+1;
		}	

	}
}
