#include<stdio.h>
#include<stack>
using namespace std;
int a[101];
stack<int> st;
int main(){
	int n;
	scanf("%d",&n);
	int max=1;
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		//printf("%d",a[i]);
		if(a[i]>=max)
		{
			for(int j=max;j<=a[i];j++)
			{
				st.push(j);	
			}
			max=a[i];
		}
		
		if(st.top()==a[i])
			st.pop();
		
		else{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
	
}
