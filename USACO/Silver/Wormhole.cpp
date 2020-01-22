#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct{
	int a;
	int b;
	int w;
}wh;

wh w[1000001];
int check[1000001];
int in[100001];
int parent1[1000001];
int g=0, flag;

vector<int> V[100005];

int find(int i){
	if(parent1[i]==i)
		return i;
	return parent1[i] = find(parent1[i]);
}

void swap(int *p1,int *p2){
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Union(int a1, int a2){
	a1=find(a1);
	a2=find(a2);
	if(a1==a2) return;
	
	if(a1>a2){
		swap(&a1,&a2);
	}	
	
	parent1[a2]=a1;
}

int N,M;

int compare(){
	for(int i=1;i<=N;i++){
		if(in[i]!=i)
			return 1;
	}
	return 0;
}

bool cmp(wh a1, wh a2){
	return a1.w>a2.w;
}

int main(){
	
	freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
	
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d ",&in[i]);
		parent1[i]=i;
	}		
		
	
	for(int i=1;i<=N;i++){
		if(in[i]==i||check[i]){
			continue;
		}
		int cur = i;
		while(1){
			if(check[cur]) break;
			check[cur]=1;
			V[g].push_back(cur);
			cur = in[cur];
		}
		g++;
	}
	
	for(int i=0;i<M;i++)
		scanf("%d %d %d",&w[i].a,&w[i].b,&w[i].w);
	int f=0;
	for(f=1;f<=N;f++)
		if(in[f]!=f) break;
	if(f==N+1){
		printf("-1"); return 0;
	}
	
	sort(w,w+M,cmp);
	
	for(int i=0; i<M;i++){
		if(find(w[i].a)!=find(w[i].b)){
			Union(w[i].a,w[i].b);
		}
		flag=1;
		for(int j=0;flag&&j<g;j++){
			int vsize = V[j].size()-1;
			for(int k=0;k<vsize;k++){
				if(find(V[j][k])==find(V[j][k+1]))
					continue;
				flag=0; break;
			}
		}
		if(flag){
			printf("%d",w[i].w);
			break;
		}
	}
	return 0;
}
