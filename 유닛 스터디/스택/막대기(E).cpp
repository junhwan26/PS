#include<stack>
using namespace std;

#include<stdio.h>

int main(){
	stack<int> st;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		st.push(temp);
	}
	int top=0;
	int ans=0;
	while(!st.empty()){
		if(st.top()>top){
			ans++;
			top=st.top();
		}
		st.pop();
	}
	printf("%d",ans);
}
