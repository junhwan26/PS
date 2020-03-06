#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int in[3];
	scanf("%d %d %d",&in[0],&in[1],&in[2]);
	sort(in,in+3);
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	int tmp=min(n,m);
	printf("%.1f",(float)(in[0]+tmp)*1.1);	
	
}
