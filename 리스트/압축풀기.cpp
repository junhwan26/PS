#include<stdio.h>
#include<stack>
#include <stdlib.h>
#include<string.h>
using namespace std;
char s[51];
stack<char> st;
stack<char> letter;



int main(){
	scanf("%s",s);
	int i=0;
	int ans=0;
	
	while(s[i]!=NULL){
		//printf("%c",s[i]);
		int len=-1;
		st.push(s[i]);
		if(s[i]==')'){
			while(st.top()!='('){
				st.pop();
				len++;		
			}
			st.pop();
			len*=st.top()-'1'+1;
			st.pop();
			for(int j=0;j<len;j++){
				st.push(1);
			}
		}
		i++;
	}
	while(!st.empty()){
		ans++;
		st.pop();
	}
	printf("%d",ans);
}
