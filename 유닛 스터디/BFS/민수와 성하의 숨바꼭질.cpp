#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
int n,k;
int check[100001];


int main(){
	scanf("%d %d",&n,&k);
	q.push(n);
	int ans=-1;
	int flag=1;
	while(flag){
		
		int size=q.size();
		for(int i=0;i<size;i++){
			
			int front=q.front();
			check[front]=1;
			
			if(front==k)
			{
				flag=0;
			}
			if(front+1<=100000&&!check[front+1])
				q.push(front+1);
		
			if(front-1<=100000&&!check[front-1])
				q.push(front-1);
		
			if(front*2<=100000&&!check[front*2])
				q.push(front*2);

			q.pop();
		}
		ans++;
	}
	printf("%d",ans);
}
