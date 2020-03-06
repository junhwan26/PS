#include<stdio.h>

int in[100];
int main(){
	int n,m;
	
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	
	int ans=0;
	
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				
				int tmp=in[i]+in[j]+in[k];
				
				if(tmp<=m&&tmp>=ans)
					ans=tmp;
				
			}
		}
	}
	
	printf("%d",ans);
}
